#include <vector>
#include <iostream>


void merge(std::vector<int>& data, int p, int q, int r) {


    std::vector<int> L;
    std::vector<int> R;

    for (int i =p; i <= q; i++) {
        L.emplace_back(data[i]);
    }

    for (int i =q+1; i <= r; i++) {
        R.emplace_back(data[i]);
    }

    R.emplace_back(INT_MAX);
    L.emplace_back(INT_MAX);

    int i =0, j = 0;
    int k = p;

    while( k <= r) {

        if (L[i] <= R[j]) {

            data[k] = L[i];
            i++;
        }
        else {

            data[k] = R[j];
            j++;
        }

        k++;
    }
}

void merge_sort(std::vector<int>& data, int start, int end) {

    if (start >= end) {
        return;
    }

    int mid = (start + end)/2;

    merge_sort(data, start, mid);
    merge_sort(data, mid+1, end);
    merge(data, start, mid, end);
}

int main (int argc, char* argv[]) {

    std::vector<int> data = {5, 3, 33, 100, 56, 4, 1, 9};
    merge_sort(data, 0, data.size()-1);


    for (int value: data) {
        std::cout << value << " ";
    }

    std::cout << '\n';
}
