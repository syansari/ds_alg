#include <iostream>
#include <vector>
#include <algorithm>

// Heap sort algorithm - uses heapify to make the tree in a given order. The order is every parent node
// in the tree is greater (or less) then its children.
// when the element is taken out into sorted array then the last element in the tree which is a leaf will be put
//in place of the element popped out. After it, heapify again need to be applied.


// uses min heapify algorithm 
void heapify(std::vector<int> &vv, const int i, const int size) {

    int l = 2*i + 1;
    int r = 2*i + 2;

    int smallest = i;

    if (l < size && vv[l] < vv[i]) {

        smallest = l;
    }

    if (r < size && vv[r] < vv[smallest]) {

        smallest = r;
    }

    if (smallest != i) {

        std::swap(vv[smallest], vv[i]);
        heapify(vv, smallest, size-1);
    }

}

void heap_sort(std::vector<int> &vv) {

    int size = vv.size();
    while (size > 0) {

        std::cout << vv[0] << ' ';
        vv[0] = vv.back();
        vv.pop_back();

        heapify(vv, 0, vv.size());
        size -= 1;
    }
} 

int main() {

    std::vector<int> vv = {3, 7, 1, 8, 4, 10, 5, 19, 6};

    int size = vv.size();
    for (int i = size/2-1; i >= 0; i--) {

        heapify(vv, i, size);
    }

    heap_sort(vv);
}
