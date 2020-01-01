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
        void add_edge(std::pair<char, char> &&);
        explicit Graph(const int size);
};

void add_edge(const std::pair<char, char>&& item) {



}

Graph::Graph(const int size) : visited_(size, false) {}



int main() {

    Graph g(26);
}