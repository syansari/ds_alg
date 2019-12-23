#include <iostream>
#include <string>
#include <math.h>

// x'AF1' = 2801


int base_conversion_16_to_10( std::string& input) {

    int value = 0;
    int exponent = input.length()-1;


    for (char c: input) {

        if ( c >= 'A' && c <= 'Z' ) {
            value += (c - 'A' + 10) * pow(16, exponent);
        }

        if (c >= '1' && c <= '9') {
            value += (c - '0') * pow(16, exponent); 
        }

        exponent--;
    }
    return value;
}


int main() {

    std::string input = "AF1";
    std::cout << base_conversion_16_to_10(input) << '\n';

    return 0;
}