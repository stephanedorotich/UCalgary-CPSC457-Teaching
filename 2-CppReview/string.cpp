#include <iostream>

int main() {
    // C char array
    char * str1 = "I am an immutable array of characters!\n";
    str1[0] = '7';
    std::cout << str1;

    // C++ strings
    std::string str2 = "I am a C++ string";
    std::string str3 = " and I can easily be concatenated with other strings\n";
    str2 = str2 + str3;
    str2.append("\nIt's also very easy to append to me!\n");
    
    if (str2.size() == str2.length()) {
        str2.append("My size and length are the same and easy to find\n");
    }
    std::cout << str2;
}
