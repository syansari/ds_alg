//
// Created by Samir Ansari on 11/3/19.
//


#include <vector>
#include <deque>
#include <iostream>

class Graph {

private:
    std::vector<std::vector<int>> adj_list_;
    std::vector<bool> visited_;

public:
    explicit Graph(int size);
    void BFS(int x);
};

Graph::Graph(int size) : visited_(size, false) {

    adj_list_.emplace_back(std::vector<int>({1, 2}));
    adj_list_.emplace_back(std::vector<int>({0, 3}));
    adj_list_.emplace_back(std::vector<int>({0, 4}));
    adj_list_.emplace_back(std::vector<int>({5, 1}));
    adj_list_.emplace_back(std::vector<int>({2, 5}));
    adj_list_.emplace_back(std::vector<int>({3, 4}));

}

void Graph::BFS(int x ) {

    std::deque<int> not_explored;

    std::fill(visited_.begin(), visited_.end(), false);

    visited_.at(x) = true;
    not_explored.push_back(0);

    while (!not_explored.empty()) {

        int vertex = not_explored.front();
        std::cout << vertex << " " << std::endl;
        not_explored.pop_front();

        for (auto i: adj_list_.at(vertex)) {

            if (!visited_[i]) {

                visited_.at(i) = true;
                not_explored.push_back(i);
            }
        }
    }
}

int main() {


    Graph g(10);

    g.BFS(0);




    }










