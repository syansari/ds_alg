//
// Created by Samir Ansari on 11/29/19.
// Rotate a NxN matrix by 90 degrees

// failed to finish this....to be continued...along with other matrix problems.


#include <iostream>

constexpr int matrix_dim {3};



void inplace_rotation(int matrix[][matrix_dim]) {


    //   [1,2,3]         [3,6,9]
    //   [4,5,6]   ==>   [2,5,8]
    //   [7,8,9]         [1,4,7]

    // consider all square one by one
    for (int i=0; i < matrix_dim/2; i++) {

        // consider the element in group of 4 in current square
        for (int j = i; j < matrix_dim-i-1; j++) {

            int temp = matrix[i][j];

            // right to top
            matrix[i][j] = matrix[j][matrix_dim-i-1];

            //bottom to right
            matrix[j][matrix_dim-i-1] = matrix[matrix_dim-1-i][matrix_dim-1-j];

            //left to bottom
            matrix[matrix_dim-1-i][matrix_dim-1-j] = matrix[matrix_dim-j-1][i];

            //temp to top
            matrix[matrix_dim-j-1][i] = temp;
        }
    }
}



void print_matrix(const int *matrix) {

    for (int r = 0; r < matrix_dim; r++) {

        for (int c = 0; c < matrix_dim; c++) {

            std::cout << matrix[r * matrix_dim] + c << ' ';
        }
        std::cout << '\n';
    }
}

void reverse_transpose(int matrix[][matrix_dim]) {

    //first reverse the rows and then transpose the matrix.

    // R E V E R S E   M A T R I X
    for (int i=0; i < matrix_dim; i++) {

        for (int j = 0, k=matrix_dim-1; k >= 0 && j < k; k--, j++) {

            std::swap(matrix[i][j], matrix[i][k]);
        }
    }


    // P R I N T   M A T R I X
    std::cout << '\n';
    for (int r = 0; r < matrix_dim; r++) {

        for (int c = 0; c < matrix_dim; c++) {

            std::cout << matrix[r][c] << ' ';
        }
        std::cout << '\n';
    }


    // T R A N S P O S E    M A T R I X
    for (int r = 0; r < matrix_dim; r++) {

        for (int c = 0; c < matrix_dim; c++) {

            if (r < c) {

                std::swap(matrix[r][c], matrix[c][r]);
            }
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    // P R I N T   M A T R I X
    for (int r = 0; r < matrix_dim; r++) {

            for (int c = 0; c < matrix_dim; c++) {


                    std::cout << matrix[r][c] << ' ';
            }
            std::cout << '\n';
    }
}


int main() {

    int matrix[][matrix_dim] = {


            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    print_matrix(reinterpret_cast<int *>(matrix));


    reverse_transpose(matrix);

    std::cout << '\n' << "After in-place rotation " << '\n';

    //print_matrix(reinterpret_cast<int *>(matrix));

}

