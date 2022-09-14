// Author: Stéphane Dorotich
// CPSC457
// Use freely

#include <iostream>

int main() {
    // Declaring and initializing local variables
    int n;
    n = 5;
    std::string str = "This is an array of characters.";

    std::cout << "n is:\t\t\t" << n << std::endl;
    std::cout << "str is:\t\t\t" << str << std::endl;

    std::cout << "the address of n is:\t" << &n << std::endl;
    std::cout << "the address of str is:\t" << &str << std::endl;

    // Creating a reference to an initialized variable
    int & r = n; // r now refers to n.
    std::cout << "r is:\t\t\t" << r << std::endl;

    // Note a reference MUST be refer to a VARIABLE when it is created
    // It cannot be only declared. The following lines both cause errors
    // int & r1 = 7;
    // int & r2;

    // Because r refers to the same memory location as n
    // when one of them changes, BOTH of them change.
    n = 17; // change n, r also changes
    std::cout << "r is:\t\t\t" << r << std::endl;

    r = 1337; // change r, n also changes
    std::cout << "n is:\t\t\t" << n << std::endl;

    // References CANNOT be changed after they are initialized
    // int newNumber = 0;
    // r = &newNumber;

    // Declaring and initializing a pointer
    int * n_ptr; // declare
    n_ptr = &n; // init
    // Pointers can only point to members of their type. The following line causes an error
    // int * n_ptr = &str

    // A pointer stores an ADDRESS
    std::cout << std::endl << "n_ptr is:\t\t" << p << std::endl;    
    // The value stored at that address can be accessed by DEREFERENCING the pointer
    std::cout << "n_ptr points to:\t" << *p << std::endl;

    // Dereferencing the pointer can be used modify the stored value
    *p = 100;
    std::cout << "n is:\t\t\t" << n << std::endl;

    // std::string can be treated as an array.
    std::cout << "str is:\t\t\t" << str << std::endl;
    std::cout << "the 0th char of str is:\t" << str[0] << std::endl;
    std::cout << "the 1st char of str is:\t" << str[1] << std::endl;
    std::cout << "the 2nd char of str is:\t" << str[2] << std::endl;
    std::cout << "the 3rd char of str is:\t" << str[2] << std::endl;

    // You can point to characters inside of a string!
    char * c = &str[2];
    *c = '@';
    std::cout << "str is:\t\t\t" << str << std::endl;
}
