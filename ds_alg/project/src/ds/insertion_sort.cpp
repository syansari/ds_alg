//
// Created by Samir Ansari on 11/13/19.
//

#include <iostream>
#include <vector>


int main() {

    std::vector<int> vv = {44, 55, 16, 1, 56, 99, 43};

    std::cout << "before sorting...";
    for (int x: vv) {

        std::cout << x << " ";
    }

    std::cout << std::endl;

    int j = 0;

    while(j < vv.size()) {

        int key = vv[j];
        int i = j-1;

        while( i >=0 && vv[i] > key) {

            vv[i+1] = vv[i];
            i = i-1;
        }

        vv[i+1] = key;
        j++;
    }


    std::cout << "after sorting...";
    for (int x: vv) {

        std::cout << x << " ";
    }
}