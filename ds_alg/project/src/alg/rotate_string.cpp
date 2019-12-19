//
// Created by Samir Ansari on 11/2/19.
//

/* string rotation is based on string reverse algorithm
 * A N S A R I
 * N A S A R I
 * N A I A R S
 * N A I R A S
 * S A R I A N <<-- FINAL ANSWER WHEN INDEX=2
 */

#include <iostream>
#include <string.h>

void reverse_string(char* str, int begin, int end) {

    while(begin < end) {

        char temp = str[begin];
        str[begin] = str[end];
        str[end] = temp;
        begin++;
        end--;
    }
}

void rotate_left(char* str, int index) {

    reverse_string(str, 0, strlen(str)-1);
    reverse_string(str, 0, index);
    reverse_string(str, index+1, strlen(str)-1);
}

void rotate_right(char* str, int index) {

}

int main() {

    char str[100] = "\0";

    std::cout << "enter string: ";
    std::cin >> str;
    std::cout << "string entered: " << str << std::endl;

    std::string stx(str);

    std::cout << stx << "\n";

    auto it = stx.begin();

    int index =2;

    std::reverse(it, stx.end());
    std::reverse(it, it+index+1);
    std::reverse(it+index+1, stx.end());

   // rotate_left(str, 2);

    std::cout << "string rotated: " << stx;

}