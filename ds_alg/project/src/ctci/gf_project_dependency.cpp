// create a directed graph. where an edge going from vertex A to B indicates A is dependent upon B. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Graph {

private:
    int size_;
    using graph_map  = std::unordered_map<char, std::unordered_set<char>>;
    using graph_pair = std::pair<char, std::unordered_set<char>>;

public:
    explicit Graph(int);
    void add_vertex(std::pair<char, char> &);
    graph_map graph;
};


Graph::Graph(int size) : size_ (size) {}

void Graph::add_vertex(std::pair<char, char> &pair) {

    for (auto& item : graph) {

        if (item.first == pair.first) {

           graph.at(pair.first).emplace(pair.second); 
           return;
        }
    }

    graph.emplace(std::pair<char, std::unordered_set<char>>(pair.first, std::unordered_set<char>({pair.second})));
}

std::vector<char> find_project_order(std::unordered_map<char, std::unordered_set<char>>& graph, std::vector<char> &project) {

    std::unordered_map<char, int> in_degree;

    for (auto x: project) {
        in_degree.emplace(x, 0);
    }

    for (auto& v: graph) {

        for (auto& l: v.second) {
        in_degree.at(l) += 1; 
        }
    }

    std::queue<char> zeros;

    for(auto& id: in_degree) {

        std::cout << id.first << " " <<  id.second << '\n';
        if (id.second == 0) {
            zeros.push(id.first);
        }
    }

    std::vector<char> topo_sort;
    
    for(auto& task: project) {

        if (zeros.empty()) {
            return topo_sort;
        }
        char z = zeros.front();
        zeros.pop();
        topo_sort.emplace_back(z);

        for (auto& v: graph) {

            for (auto l: v.second) {

                if (!--in_degree[l]) {
                    zeros.push(l);
                }
            }
        }
    }

    std::cout << '\n';
    return std::move(topo_sort);
}


int main() {

    std::vector<char> project = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<std::pair<char, char>> dependency;

    dependency.emplace_back(std::pair<char, char>('d', 'a'));
    dependency.emplace_back(std::pair<char, char>('b', 'f'));
    dependency.emplace_back(std::pair<char, char>('d', 'b'));
    dependency.emplace_back(std::pair<char, char>('a', 'f'));
    dependency.emplace_back(std::pair<char, char>('c', 'd'));

    Graph g(project.size());

    for (std::pair<char, char> item: dependency) {

        g.add_vertex(item);
    }

    std::vector<char> topo_sort = find_project_order(g.graph, project);

    for (auto x: topo_sort) {

        std::cout << x <<  " ";
    }

    std::cout << "\n";
}