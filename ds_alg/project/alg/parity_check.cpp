//
// Created by Samir Ansari on 10/12/19.
//

#include <iostream>
#include <algorithm>

// O(logn) - time complexity
short parityCheck(unsigned long num) {

    short count = 0;

    num ^= num >> 32;
    num ^= num >> 16;
    num ^= num >> 8;
    num ^= num >> 4;
    num ^= num >> 2;

    return num &1;
}

// O(n) - time complexity - brute force
short parityCheck(unsigned int num) {

    short count = 0;

    while(num) {

        count += num&1;
       num >>= 1;
    }
    return count;
}


void swapBits(unsigned int &num, int i, int j) {

   std::cout << "ith bit: " << int (1L << (sizeof(int)*8 - i-1) & 0x01) << std::endl;
   std::cout << "jth bit: " << int (1L >> (sizeof(int)*8 - j-1) & 0x01) << std::endl;

   unsigned int bit1 = (num >> i) & 1;
   unsigned int bit2 = (num >> i) & 1;

   unsigned int x = (bit1 ^ bit2);

   x = (x << i) | (x << j);

   unsigned int result = num ^ x;
}

void displayBits(unsigned int num) {

    std::string str;

    while(num) {

        str.append(std::to_string(num&1));
        num >>=1;
    }

    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;
}

int main() {

    unsigned int num = 100;
    std::cout << "enter an integer value: ";
    std::cin >> num;
    std::cout << parityCheck(num) << std::endl;
    std::cout << "size of integer: " << sizeof(int) << " bytes" << std::endl;

    displayBits(num);

    swapBits(num, 30, 31);
}