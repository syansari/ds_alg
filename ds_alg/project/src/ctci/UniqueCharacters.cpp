//
// Created by Samir Ansari on 11/21/19.
//
// algorithm to check if a string has all unique characters.


#include <string>
#include <algorithm>
#include <iostream>

class UniqueCharacters {

private:
    std::string str_;
public:
    bool operator()();

    explicit UniqueCharacters(std::string &&str);
};



UniqueCharacters::UniqueCharacters(std::string &&str) : str_(str) {};

bool UniqueCharacters::operator()() {

    std::sort(str_.begin(), str_.end());

    std::string::const_iterator it = str_.begin();

    while(it != str_.end()) {

        if (*it == *(it+1)) {
            return false;
        }
        ++it;
    }

    return true;
}

int main() {


    UniqueCharacters uniqueChars("right");

    std::cout << (uniqueChars() ? "true" : "false");

}
