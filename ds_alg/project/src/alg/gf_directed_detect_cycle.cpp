#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>

class Graph {

    private:    
        std::unordered_map<char, std::unordered_set<char>> graph_;
        std::deque<bool> visited_;
    public:
        void add_edge(const std::pair<char, char> &&);
        bool has_cycle(const char, std::deque<char>&);
        explicit Graph(const int size);
        
};

bool Graph::has_cycle(const char vertex, std::deque<char>& stck) {

    visited_[vertex - 'a'] = true;
    stck.emplace_back(vertex);

    for (char item: graph_.at(vertex)) {

        if (visited_[item - 'a'] == false) {

            bool result = has_cycle(item, stck);
            stck.pop_back();
            return result;
        }

        else if (std::find(stck.begin(), stck.end(), item) != stck.end()) {
    
            return true;
        }
    }

    return false;
}


void Graph::add_edge(const std::pair<char, char>&& item) {

    if (graph_.find(item.second) == graph_.end()) {

        graph_.emplace(item.second, std::unordered_set<char>({}));
    }


    if (graph_.find(item.first) == graph_.end()) {

        graph_.emplace(item.first, std::unordered_set<char>({item.second}));
        return;
    }

    graph_.at(item.first).emplace(item.second);
}


Graph::Graph(const int size) : visited_(size, false) {}


int main() {

    Graph g(26);

    g.add_edge(std::pair<char, char>('a', 'b'));
    g.add_edge(std::pair<char, char>('b', 'c'));
    g.add_edge(std::pair<char, char>('c', 'd'));
    g.add_edge(std::pair<char, char>('d', 'e'));
    g.add_edge(std::pair<char, char>('e', 'f'));
    g.add_edge(std::pair<char, char>('a', 'f'));

    std::deque<char> stck;
    std::cout << "has cycle: " << g.has_cycle('a', stck) << '\n';

}

