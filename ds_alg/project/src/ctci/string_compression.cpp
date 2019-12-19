//
// Created by Samir Ansari on 11/29/19.
//

// aaaabbbccddd --> a4b3c2d3
// time complexity O(n), space complexity O(n)

#include <string>
#include <iostream>
#include <memory>


/* this function takes a string, compress it and return
 * the compressed string.
 * If the string is not compressed then it will return the
 * original string.
 *
 * use make_unique, and make_shared. help avoid
 * memory leaks. they are available starting C++14
 *
 */

std::unique_ptr<std::string> compress_string(const std::string &str) {

    auto it  = str.begin();
    auto it_next = str.begin();

    //std::unique_ptr<std::string> str_ptr(new std::string(""));
    auto str_ptr = std::make_unique<std::string>("");
    int count = 0;


    while(it != str.end()) {

        if (*it == *it_next) {

            count++;
            ++it_next;
        }
        else {

            str_ptr->push_back(*it);

            if (count > 1) {

                str_ptr->push_back(count + 0x30);
            }

            count = 0;
            it = it_next;
        }
    }

    return str_ptr;
}


int main() {


    std::string input_string = "aaaabbbccd";

    std::cout << *compress_string(input_string) << '\n';
}