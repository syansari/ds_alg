//
// Created by Samir Ansari on 11/21/19.
//
// Permutation of one another

#include <string>
#include <algorithm>
#include <iostream>

class PermutationOfOneAnother {

public:
    bool operator()( std::string &s1,  std::string &s2);

};


bool PermutationOfOneAnother::operator()( std::string &s1,  std::string &s2) {


    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    return (s1 == s2);
}


int main() {

    PermutationOfOneAnother permutationOfOneAnother;

    std::string s1 = "abc";
    std::string s2 = "bca";

    std::cout << (permutationOfOneAnother(s1, s2) ? "true" : "false");
}