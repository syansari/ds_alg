//
// Created by Samir Ansari on 11/20/19.
//
// Heap sort algorithm - uses heapify to make the tree in a given order. The order is every parent node
// in the tree is greater (or less) then its children.
// when the element is taken out into sorted array then the last element in the tree which is a leaf will be put
//in place of the element popped out. After it, heapify again need to be applied.

#include <vector>
#include <iostream>
#include <atomic>


void max_heapify(std::vector<int> &vv, int i, const int size) {

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if ( l <= size && vv[l] > vv[i]) {

        largest = l;
    }

    if ( r <= size && vv[r] > vv[i] && vv[r] > vv[largest]) {

        largest = r;
    }

    if (largest != i) {

        std::swap(vv[largest], vv[i]);
        max_heapify(vv, largest, size-1);
    }
}

void heap_sort(std::vector<int> &vv) {

    std::vector<int> sorted;
    int size = vv.size();

    while (size > 0) {

        sorted.insert(sorted.begin(), vv[0]);

        vv[0] = vv.back();
        vv.pop_back();

        max_heapify(vv, 0, vv.size());
        size -= 1;
    }

    for (auto x: sorted) {

        std::cout << x << " ";
    }
}

int main() {

    std::vector<int> vv = {5, 9 , 3, 7, 16, 8 , 4, 1};

    for (int i = (int)vv.size()/2 -1; i >= 0; i--) {

        max_heapify(vv, i, vv.size());
    }

    heap_sort(vv);
}