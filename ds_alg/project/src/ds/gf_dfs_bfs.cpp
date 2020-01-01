#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>

class Graph {

private:
    std::unordered_map<char, std::unordered_set<char>> adj_list_;
    std::deque<bool> visited_;
    std::queue<char> unexplored_;

public: 
    void add_edge(std::pair<char, char> &&);
    void bfs(const char) ;
    void dfs(const char);
    explicit Graph(const int size);
};

Graph::Graph(const int size) : visited_(size, false) {}

void Graph::dfs(char vertex) {

    std::cout << vertex << " ";
    visited_[vertex - 'a'] = true;

    for (char value: adj_list_.at(vertex)) {

        if (visited_[value - 'a'] == false ) {

            dfs(value);
        }
    }
}

void Graph::bfs(char vertex) {


    visited_[vertex - 'a'] = true;

    unexplored_.push(vertex);

    while(!unexplored_.empty()) {

        vertex = unexplored_.front();
        unexplored_.pop();
        std::cout << vertex << " ";

        for (char value : adj_list_.at(vertex)) {

            if ( visited_[value - 'a'] == false) {

                visited_[value - 'a'] = true;
                unexplored_.push(value);
            }
        }
    }

    std::cout << '\n';
}


void Graph::add_edge(std::pair<char, char>&& item) {

    if (adj_list_.find(item.first) == adj_list_.end()) {

        adj_list_.emplace(std::pair<char, std::unordered_set<char>>(item.first, std::unordered_set<char>({item.second})));
    }

    adj_list_.at(item.first).emplace(item.second);
}

int main() {

    Graph g(26);

    g.add_edge(std::pair<char, char>('a', 'b'));
    g.add_edge(std::pair<char, char>('a', 'c'));
    g.add_edge(std::pair<char, char>('b', 'd'));
    g.add_edge(std::pair<char, char>('c', 'e'));
    g.add_edge(std::pair<char, char>('d', 'f'));
    g.add_edge(std::pair<char, char>('e', 'f'));
    g.add_edge(std::pair<char, char>('f', 'd'));
    g.add_edge(std::pair<char, char>('f', 'e'));

  //  g.bfs('a');
    g.dfs('a');

}