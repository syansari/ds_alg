//
// Created by Samir Ansari on 11/17/19.
//

//  longest common prefix

#include <vector>
#include <string>
#include <iostream>

bool isLongestCommonPrefix(std::vector<std::string> &vv, int mid) {

    std::string str = vv[0].substr(0, mid);

    for (const auto &x: vv) {

        if (x.substr(0, mid) != str) {

            return false;
        }
    }
    return true;
}

std::string longestCommonPrefix(std::vector<std::string> &vv, int min) {

    std::string str = vv[0].substr(0, min);

    int low = 1;
    int high = min;

    int mid = (low + high) / 2;

    while (mid <= high) {

        for (const auto &x: vv) {

            if (isLongestCommonPrefix(vv, mid)) {

                 mid += 1;
            } else {

                 mid -= 1;
            }

            return vv[0].substr(0, mid);
        }
    }
}


int main() {

    std::vector<std::string> vv = {"rstuwrwrwrw", "rstuvxy", "rstuvgdgdgdgdgd", "rstuvdvgddbdbdfbdfdf"};

    int min = INT32_MAX;

    for (const auto &x: vv) {

        if (x.size() < min) {

            min = x.size();
        }
    }

    std::cout << longestCommonPrefix(vv, min) << std::endl;

}
