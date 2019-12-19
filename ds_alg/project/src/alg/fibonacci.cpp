//
// Created by Samir Ansari on 10/27/19.
//

#include <iostream>

using namespace std;

static int fib_rec(int n) {

    if (n <= 1) {

        return n;
    }

    return fib_rec(n-1) + fib_rec(n-2);
}


static int fib_itr(int n) {

    return n;
}


int main() {

    int num = 11;
    cout << "recursive answer: " << fib_rec(num) << endl;
    cout << "iterative answer: " << fib_itr(num) << endl;
}
