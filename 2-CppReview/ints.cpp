// Integer types
// Author: Xining Chen, Stéphane Dorotich
// CPSC 457
// Use freely

#include <iostream>
#include <climits>
#include <cstdint>

int main()
{
    short n1;
    int n2;
    long n3;
    
    std::cout << "Min/Max of Integer Types\n";
    std::cout << "\tshort min:\t" << SHRT_MIN << std::endl;
    std::cout << "\tshort max:\t"<< SHRT_MAX << std::endl;
    std::cout << "\tint min:\t" << INT_MIN << std::endl;
    std::cout << "\tint max:\t"<< INT_MAX << std::endl;
    std::cout << "\tlong min:\t" << LONG_MIN << std::endl;
    std::cout << "\tlong max:\t" << LONG_MAX << std::endl;

    std::cout << "\nStorage Size of Integer Types (bytes)\n";
    std::cout << "\tshort:\t\t" << sizeof(short) << std::endl;
    std::cout << "\tint:\t\t" << sizeof(int) << std::endl;
    std::cout << "\tlong:\t\t" << sizeof(long) << std::endl;

    std::cout << "\nFixed Size Integer Types (bytes)\n";
    std::cout << "\tint8_t:\t\t" << sizeof(int8_t) << std::endl;
    std::cout << "\tint16_t:\t" << sizeof(int16_t) << std::endl;
    std::cout << "\tint32_t:\t" << sizeof(int32_t) << std::endl;
    std::cout << "\tint64_t:\t" << sizeof(int64_t) << std::endl;
    return 0;
}
