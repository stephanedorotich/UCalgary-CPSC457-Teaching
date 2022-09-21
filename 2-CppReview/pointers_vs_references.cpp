// Author: Stéphane Dorotich
// CPSC457
// Use freely

#include <iostream>

int main() {

    // Value
    int n;  // Declare      Allocate memory
    n = 5;  // Init         Store value at memory location

    // Reference
    int & n_ref = n; // Declare & Init

    // Pointer
    int * n_ptr; // Declare     Allocate memory
    n_ptr = &n;  // Init        Store value at memory location

    std::cout << "n:\t\t" << n << std::endl; // variable
    std::cout << "n_ref:\t\t" << n_ref << std::endl; // reference
    std::cout << "*n_ptr:\t\t" << *n_ptr << std::endl; // dereferenced pointer
    std::cout << "&n:\t\t" << &n << std::endl; // address of variable
    std::cout << "n_ptr:\t\t" << n_ptr << std::endl; // pointer

    std::cout << std::endl;

   
    std::string str = "This is an array of characters.\n";

    std::cout << "str:\t\t" << str;
    std::cout << "&str:\t\t" << &str << std::endl;

    // C++ strings are mutable (they can be modified!)
    char * c = &str[2];
    *c = '@';
    std::cout << "str:\t\t" << str;
}
