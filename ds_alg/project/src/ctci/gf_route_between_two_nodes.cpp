// given a directed graph, find route between two nodes.

#include <iostream>
#include <vector>
#include <deque>

class Graph {

private:
    std::vector<std::vector<int>> adj_list_;
    std::vector<bool> visited_;

public:
    explicit Graph(const int size);
    bool is_route_present_using_bfs(const int, const int, const int);
    bool is_route_present_using_dfs(const int, const int);
};

// create graph using adjacency list 
Graph::Graph(const int size) : visited_(size, false) {

    adj_list_.emplace_back(std::vector<int>{1, 2});
    adj_list_.emplace_back(std::vector<int>{3});
    adj_list_.emplace_back(std::vector<int>{4});
    adj_list_.emplace_back(std::vector<int>{});
    adj_list_.emplace_back(std::vector<int>{5});
    adj_list_.emplace_back(std::vector<int>{3});
}


// traverse the graph until hit by the node interested in..
bool Graph::is_route_present_using_bfs(const int src_vertex, const int dst_vertex, const int size) {

    std::deque<int> not_explored;

    not_explored.emplace_back(src_vertex);
    visited_[src_vertex] = true;

    while (!not_explored.empty()) {

        int current_vertex = not_explored.front();
        not_explored.pop_front();

        for (int i : adj_list_[current_vertex]) {

            if (i == dst_vertex) {

                return true;
            }

            if (visited_[i] != true) {

                visited_[i] = true;
                not_explored.emplace_back(i);
            }
        }
    }
    return false;
}

bool Graph::is_route_present_using_dfs(const int src_vertex, const int dst_vertex) {

    visited_[src_vertex] = true;

    for (int i: adj_list_[src_vertex]) {

        if (i == dst_vertex) {

            return true;
        }

        if (visited_[i] == false) {

            if (is_route_present_using_dfs(i, dst_vertex) == true) {
                
                return true;
            }
        }
    }

    return false;
}


int main() {

    Graph g1(6);
    std::cout << (g1.is_route_present_using_bfs(0, 3, 6) ? "true" : "false") << '\n'; 
    Graph g2(6);  
    std::cout << (g2.is_route_present_using_dfs(0, 5) ? "true" : "false") << '\n';

}