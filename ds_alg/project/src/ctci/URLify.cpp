//
// Created by Samir Ansari on 11/21/19.
//
// given a string, replace space character in a string with "%20"


#include <string>
#include <iostream>
#include <vector>
#include <regex>


class URLify {

public:
    void operator()(std::string &str);

};

void URLify::operator()(std::string &str) {

    const std::string &whitespaces(" \t\f\v\n\r");

    // trim leading and trailing whitespaces around the string
  str = std::regex_replace(str, std::regex("^\\s+"), std::string(""));
  str = std::regex_replace(str, std::regex("\\s+$"), std::string(""));

  // replace whitespace with "%20"
  str = std::regex_replace(str, std::regex("[[:space:]]"), "%20");
}


int main() {

    std::string str = " Mr John\tSmith ";

    URLify urLify;

    std::cout << str  << '\n';

    urLify(str);

    std::cout << str << std::endl;

}