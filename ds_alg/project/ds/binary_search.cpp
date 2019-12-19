//
// Created by Samir Ansari on 11/17/19.
//

#include <vector>
#include <iostream>


int binarySearch(std::vector<int> &vv, int lo, int hi, int num) {

    if (lo == hi) {

        return -1;
    }

    int mid = (hi + lo) / 2;

    if (vv[mid] == num) {

        return mid;
    }

    if (vv[mid] > num) {

        binarySearch(vv, lo, mid-1, num);
    }
    else {

        binarySearch(vv, mid+1, hi, num);
    }
}

int main() {


    std::vector<int> vv = {1, 2, 3, 4, 10, 20, 33, 49, 67, 110, 119, 223, 554, 999};

    std::cout << "the search value is: " << binarySearch(vv, 0, vv.size(), 119);

}