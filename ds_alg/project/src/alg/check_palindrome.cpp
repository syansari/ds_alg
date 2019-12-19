//
// Created by Samir Ansari on 11/25/19.
//



#include <iostream>
#include <string>
#include <algorithm>


bool isPalindrome(std::string& str) {

    int size = str.size();
    auto it = str.begin();

    std::string strr = str;
    std::reverse(strr.begin(), strr.end());

    //std::cout << str << "  " << strr << " ";
    if (str == strr) {

        std::cout << "string is palindrome" << '\n';
        return true;
    }
    else {

        std::cout << "string is not a palindrome" << '\n';
    }

    return false;

}


int main() {

    std::string str = "nitin";  
    // logic to get the permutation.

    isPalindrome(str);

}