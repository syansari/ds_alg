//
// Created by Samir Ansari on 10/25/19.
// Merge Sort algorithm
//

#include <vector>
#include <iostream>

using namespace std;

class MergeSort {

public:

    MergeSort(vector<int> &data) : data_(&data) {cout << "object initialized "; }

//    MergeSort operator=(vector<int> &data) { data_ = &data; }


    void apply_merge_sort() {

        merge_sort(0, data_->size()-1);
    }

private:
    vector<int>* data_;

    void merge_sort(int start, int end);
    void merge(int start, int mid, int end);
};



void MergeSort::merge_sort(int start, int end) {


    if (start < end ) {

        int mid = (start + end) / 2;

        merge_sort(start, mid);
        merge_sort(mid+1, end);
        merge(start, mid, end);
    }
}

void MergeSort::merge(int start, int mid, int end) {


        int n1 = mid - start + 1;
        int n2 = end - mid;

        vector<int> L(n1);
        vector<int> R(n2);

        /* sort and merge the two arrays */
        for (int i=0; i < n1; i++ ) {

            L[i] = data_->at(start+i);
        }

        for (int i=0; i < n2; i++) {

            R[i] = data_->at(mid+1+i);
        }

        int i =0, j=0, k=0;

        while(i < n1 && j < n2) {




        }


}





int main (int argc, char* argv[]) {


    vector<int> data = {5, 3, 33, 100, 56, 4, 1, 9};

    MergeSort mm(data);

   // mm.apply_merge_sort();

   vector<int> a1(5);
}
