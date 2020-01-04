//
// Created by Samir Ansari on 10/27/19.
//

#include <iostream>
#include <vector>

// uses the dynamic programming approach to store the result of sub-problem in mem vector and 
// resuse it when encountered while solving a separate sub problem. 
static int top_down_approach(int n, std::vector<int>& mem) {

    if (n == 0) return 0;
    if (n == 1) return 1;

    if (mem[n] != 0) {
        return mem[n]; 
    }
    else {

        mem[n] = top_down_approach(n-1, mem) + top_down_approach(n-2, mem);
        return mem[n];
    }
}


// recurivse solution. 
static int fib_rec(int n) {

    if (n <= 1) {

        return n;
    }

    return fib_rec(n-1) + fib_rec(n-2);
}

// iterative solution 
static int fib_itr(int n) {

    if (n <= 1) {

        return n;
    }

    int ppn, pn = 0, cn = 1; // ppn = previous previous number, pn = previous number, cn = current number

    for (int i = 1; i < n; i++) {

        ppn = pn;
        pn = cn;
        cn = ppn + pn;
    }

    return cn;
}


int main() {

    int num = 11;
    std::cout << "recursive answer: " << fib_rec(num) << '\n';
    std::cout << "iterative answer: " << fib_itr(num) << '\n';

    std::vector<int> mem(num+1, 0);
    std::cout << "top down approach: " << top_down_approach(num, mem) << '\n';

}
