//
// Created by Samir Ansari on 11/20/19.
//
//  input : "abccabdb" , output: "cabd"
//  input " "bbbbbbb" , output: "b"

#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <unordered_set>


std::vector<char> brute_force(const std::string &str) {

    std::vector<char> vc;
    std::vector<char> longest;

    std::string::const_iterator it = str.begin();

    while (it != str.end()) {

        auto is = it;
        vc.clear();

        while (is != str.end()) {

            if (vc.empty()) {

                vc.emplace_back(*is);
                is++;
                continue;
            }

            if (std::find(vc.begin(), vc.end(), *is) == vc.end()) {

                vc.emplace_back(*is);
            } else {
                break;
            }
            is++;
        }

        if (vc.size() > longest.size()) {

            longest = vc;
        }
        it++;
    }

    return longest;
}

/* this returns the length og the longest substring */
unsigned int optimizedSolution(const std::string &str) {

    std::unordered_set<int> set;
    int max = 0;

    int size = str.size();

    int i=0, j=0;

    while (i < size && j < size) {

        set.emplace(str[j++]);

        if (set.find(str[j]) != set.end()) {

            set.erase(str[i++]);
        }

        max = std::max(max, j-i);
    }

    return max;

}


int main() {

    std::string str = "pwwkew";

/*
    std::vector<char> longest = brute_force(str_);

    for (char x: longest) {

        std::cout << x << " ";
    }
*/

    std::cout << "max length of substring: " << optimizedSolution(str) << "\n";
}