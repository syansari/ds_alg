//
// Created by Samir Ansari on 10/30/19.
//

#include <iostream>


bool isPrime(int num) {

    if (num <= 1) {

        return true;
    }

    for (int i=2; i < num; i++) {

        if (!(num % i)) {

            return false;
        }
    }

    return true;
}



int main(int argc, char *argv[]) {


    int number, i = 0;

    std::cout << "Enter the max number: ";
    std::cin >> number;

    while (++i <= number) {

        if (isPrime(i)) {

            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}