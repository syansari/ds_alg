//
// Created by Samir Ansari on 10/21/19.
// Quick sort algorithm
//

#include <vector>
#include <iostream>
#include <algorithm>

template <class T> class QSAlg {

public:
    QSAlg(std::vector<T> &data ) : input_(&data) { std::cout << "input initialized" << std::endl;}

    QSAlg operator = (std::vector<T>  &data) { input_ = &data; }

    void quick_sort() {

        quick_sort(*input_, 0, input_->size()-1);
    }

private:
    std::vector<T> *input_;   // data to sort

    // partition algorithm
    int partition (std::vector<T> &vec, int start, int end) {

        T pivot = vec[end];
        int i = start-1;

        for (int j = start; j <= end-1; j++) {

             if (vec[j] <= pivot) {

                i++;
                iter_swap(vec.begin() + j, vec.begin() + i);
            }   
        }
        std::swap(vec[i+1], vec[end]);
        return ++i;
    }

    void quick_sort(std::vector<T> &data, int start, int end) {

        if (start < end ) {

            int p = partition(data, start, end);
            quick_sort(data, start, p-1);
            quick_sort(data, p, end);
        }
    }
};

int main() {

    std::vector<int> input = {5, 3, 33, 100, 56, 4, 1, 9};
   // QSAlg<int> qsAlg(input);

    QSAlg<int> qsAlg = input;

    qsAlg.quick_sort();

    std::cout << "sorted array: ";
    for ( auto i: input) {
        std::cout << i << " ";
    }

    std::cout << std::endl << " end of program";
}