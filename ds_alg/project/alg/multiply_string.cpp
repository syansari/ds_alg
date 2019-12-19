//
// Created by Samir Ansari on 11/9/19.
//
// "12" x "12" = "144"


#include <string>
#include <ostream>
#include <iostream>
#include <cstring>
#include <sstream>


int main() {

    std::string str1 = "12";
    std::string str2 = "12";

    int x1 = atoi(str1.c_str());
    int x2 = atoi(str2.c_str());

    int x3 = x1*x2;

    std::stringstream sm;

    sm << x3;

    std::cout << sm.str() << std::endl;


}


