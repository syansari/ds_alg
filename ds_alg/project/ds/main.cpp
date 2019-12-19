#include <iostream>
#include <vector>
#include <algorithm>
#include "main.h"

using namespace std;

int main() {

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << vec.back() << endl;

    cout << vec.size() << "  " << distance(vec.begin(), find(vec.begin(), vec.end(), 7)) << endl;

    return 0;
}