#include <vector>
#include <iostream>
#include <deque>

class CountIsland {

private:
    using matrix_int = std::vector<std::vector<int>>;
    using matrix_bool = std::deque<std::deque<bool>>;
    std::vector<std::vector<int>> region_;
    const int neighbor_count = 8;

public:
    explicit CountIsland (std::vector<std::vector<int>> &);
    void bfs(std::pair<int, int>);
    void check_neighbors(std::pair<int, int>);
    matrix_bool processed_ = matrix_bool(10, std::deque<bool>(10, false));
};

void CountIsland::check_neighbors(std::pair<int, int> point) {

    int neighbors_row[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int neighbors_col[] = {-1, -1, -1, 0, 1, 1, 1, 0};

    for (int i =0; i < neighbor_count; i++) {

        int x = point.first + neighbors_row[i];
        int y = point.second + neighbors_col[i];

          //if ( 0 <= x < region_.size() && 0 <= y < region_.size() && region_[x][y] && !processed_[x][y] );
          if ( x >= 0 && x < region_.size() && y >= 0 && y < region_.size() && region_[x][y] && !processed_[x][y] ) {

            processed_[x][y] = true;
            check_neighbors(std::pair<int,int>(x, y));
        }   
    }
}


CountIsland::CountIsland(matrix_int & region) : region_(region) {};

void CountIsland::bfs(std::pair<int, int> point) {

    processed_[point.first][point.second] = true;
    check_neighbors(point);
}


int main() {

    int island_count = 0;
    std::vector<std::vector<int>> region = {
        
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
        {'0','0','0','0','0'},
    };

    CountIsland ci(region);

    for (int i = 0; i < region.size()-1; i++) {

        for (int j = 0; j < region.size()-1; j++) {

            if (region[i][j] && !ci.processed_[i][j]) {
            
                ci.bfs(std::move(std::pair<int, int>(i, j)));
                island_count++;
            }
        }
    }

    std::cout << "number of islands found: " << island_count << '\n';
}