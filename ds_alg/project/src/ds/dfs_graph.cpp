//
// Created by Samir Ansari on 11/9/19.
//


#include <vector>
#include <iostream>

class Graph {

private:
    std::vector<std::vector<int>>  adj_list_;
    std::vector<bool> visited_;

public:
    explicit Graph(int size);
    void dfs(int vertex);
};

Graph::Graph(int size) :  visited_(10, false) {

    adj_list_.emplace_back(std::vector<int>({1, 2}));
    adj_list_.emplace_back(std::vector<int>({0, 3}));
    adj_list_.emplace_back(std::vector<int>({0, 4}));
    adj_list_.emplace_back(std::vector<int>({5, 1}));
    adj_list_.emplace_back(std::vector<int>({2, 5}));
    adj_list_.emplace_back(std::vector<int>({3, 4}));
}

void Graph::dfs(int vertex) {

    visited_[vertex] = true;
    std::cout << vertex << " ";

    for (int i: adj_list_[vertex]) {

        if (!visited_[i]) {
            dfs(i);
        }
    }
}

int main() {

    Graph g(10);
    g.dfs(0);
    std::cout << '\n';
}



