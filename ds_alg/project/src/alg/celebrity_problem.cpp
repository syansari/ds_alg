//
// Created by Samir Ansari on 11/20/19.

// https://codebasil.com/problems/the-celebrity-problem


#include <iostream>

bool confirm_celeb(int relationship[][3], int row , int probable_celeb) {


    for (int j = 0; j < row; j++) {

        if (!relationship[j][probable_celeb]) {

            return false;
        }
    }

    return true;
}


int main() {

    // there are 3 people in the room

    int relationship[][3] = {

            {1, 0, 0},
            {1, 1, 1},
            {0, 1, 1}
    };

    int row = sizeof(relationship) / sizeof(relationship[0]);

    int probable_celeb = -1;

    for (int i = 0; i < row; i++) {

        if (relationship[i][i + 1] && relationship[i + 1][i]) {
            continue;
        }

        if (relationship[i][i + 1]) {

            probable_celeb = i + 1;
            if (confirm_celeb(relationship, row, probable_celeb)) {

                std::cout << "celeb index is: " << probable_celeb;
                exit(0);
            }
        }

        if (relationship[i + 1][i]) {

            probable_celeb = i;

            if (confirm_celeb(relationship, row, probable_celeb)) {

                std::cout << "celeb index is: " << probable_celeb;
                exit(0);
            }
        }
    }

    std::cout << "No celeb present in the room";
}


