//
// Created by Samir Ansari on 11/25/19.
//


#include <string>
#include <iostream>
#include <stdexcept>


bool check_when_unequal_size(const std::string &str1, const std::string &str2) {

    auto it1 = str1.begin();
    auto it2 = str2.begin();
    int diff_count = 0;

    while (it2 != str2.end()) {

        if (*it1 == *it2) {

            it1++;
            it2++;
            continue;
        }
        diff_count++;
        it1++;
    }

    return diff_count ==0 || diff_count == 1;
}


bool check_when_equal_size(const std::string &str1, const std::string &str2) {

    if (str1 == str2) {

        return true;
    }

    auto it1 = str1.begin();
    auto it2 = str2.begin();
    int diff_count = 0;

    while (it1 != str1.end() && it2 != str2.end()) {

        if (*it1 != *it2) {
            diff_count++;
        }
        it1++;
        it2++;
    }

    return diff_count == 1;
}


bool is_one_way(const std::string &str1, const std::string &str2) {

    int size1 = str1.size();
    int size2 = str2.size();

    if (str1.size() == str2.size()) {

        return check_when_equal_size(str1, str2);
    }

    if ((size1 > size2) && (size1 - size2 == 1)) {

        return check_when_unequal_size(str1, str2);
    }

    if ((size2 > size1) && (size2 - size1 == 1)) {

        return check_when_unequal_size(str2, str1);
    }

    return false;
}


int main() {


    std::string str1 = "puke";
    std::string str2 = "puk";

    std::cout << (is_one_way(str1, str2) ? "true" : "false") << '\n';

}