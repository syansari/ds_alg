#include <iostream>
#include <deque>
#include <unordered_map>
#include <unordered_set>

class Graph {

    private:
        std::unordered_map<char, std::unordered_set<char>> graph_;
        std::deque<bool> visited_;
    
    public:
        Graph(const int size) : visited_(26, false) {}
        void add_edge(const std::pair<char, char> &&);
        bool has_cycle(const char, const char);
};

void Graph::add_edge(const std::pair<char, char> && item) {

    if (graph_.find(item.second) == graph_.end()) {

        graph_.emplace(item.second, std::unordered_set<char>({item.first}));
    }
    else {

        graph_.at(item.second).emplace(item.first);
    }

    if (graph_.find(item.first) == graph_.end()) {

        graph_.emplace(item.first, std::unordered_set<char>({item.second}));
    }
    else {

        graph_.at(item.first).emplace(item.second);
    }
}

bool Graph::has_cycle(const char vertex, const char parent) {

    visited_[vertex - 'a'] = true;

    for (char v: graph_.at(vertex)) {

        if (visited_[v - 'a'] == true && v != parent) {
            return true;
        }
    }

    for (char v: graph_.at(vertex)) {
        
        if (visited_[v - 'a'] != true) {
            return has_cycle(v, vertex);
        }
    }

    return false;
}

int main() {

    Graph g(26);

    g.add_edge(std::pair<char, char>('a', 'b')); // a -> b
    g.add_edge(std::pair<char, char>('a', 'd')); // a -> d
    g.add_edge(std::pair<char, char>('d', 'b')); // d -> b
    g.add_edge(std::pair<char, char>('b', 'c')); // b -> c
    g.add_edge(std::pair<char, char>('c', 'e')); // c -> e


    std::cout << "has cycle: " << std::boolalpha << g.has_cycle('a', -1) << '\n';

}
