//
// Created by Samir Ansari on 11/25/19.
// time complexity is O(n)


#include <iostream>
#include <string>
#include <set>


int main() {


    std::string str = "taco  tac";

    int size = str.size();


    std::set<char> ss;

    for (auto x: str) {

        ss.emplace(x);
    }


    if ((size % 2 == 0) && (ss.size() == size / 2)) {

        std::cout << "its a palindrome permutation" << '\n';
        exit(0);
    }

    if ((size % 2 != 0) && (ss.size() == (size / 2) + 1)) {

        std::cout << "its a palindrome permutation" << '\n';
        exit(0);
    }

    std::cout << "its not a palindrome permutation" << '\n';

}