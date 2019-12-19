//
// Created by Samir Ansari on 11/30/19.
//

#include <string>
#include <iostream>


bool isSubString(const std::string &str1, const std::string &str2) {

    return str1.find(str2) != std::string::npos;
}


bool isRotation( std::string &str1,  std::string &str2) {

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    return str1 == str2;
}

int main() {

    std::string str1 = "waterbottle";

    std::string str2 = "tlewaterbot";

    std::cout << (isRotation(str1, str2) ? "True" : "False") << '\n';
}