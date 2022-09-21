// Author: Xining Chen, Stéphane Dorotich
// CPSC 457
// Use freely

// Different ways of looping through a vector
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> my_vec = {"first", "second", "last"};

    //  1)  Loop by making a copy of each element in vector.
    //      Copy made is by value.
    //      Changes to the copy do not change the original element. 
    std::cout << "Loop with copies\n";
    for (std::string s : my_vec)
    {
        s = s + "_copy";
        std::cout << "\t" << s << std::endl;
    }

    //  2)  Loop by making a read-only copy of each element
    //      using keyword 'const'.
    //      s is still a copy of the elements in my_vec.
    std::cout << "\nLoop with constant copies\n";
    for (const std::string s : my_vec)
    {
        // s = s + "_copy_const"; // compilation error
        std::cout << "\t" << s << std::endl;
    }

    // 3)   Pass by reference, passes the stored values themselves
    //      Keyword 'auto' allows compiler to deduce the type stored
    //      in the container.
    std::cout << "\nLoop with references\n";
    for (auto & s: my_vec)
    {
        s = s + "_ref";
        std::cout << "\t" << s << std::endl;
    }

    // 4)   Pass by constant reference
    //      Values of container cannot be modified
    //      Ideal implementation because it is SAFE and FAST
    std::cout << "\nLoop with constant references\n";
    for (const auto & s : my_vec)
    {
        // s = s + "_ref_const"; // compilation error
        std::cout << "\t" << s << std::endl;
    }

    // std::unordered_map<std::vector<std::pair<int, std::string>>> myMap;
}