// Author: Xining  Chen, Stéphane Dorotich
// CPSC 457
// Use freely

/*
Vectors in C++
Vector container - dynamically allocated arrays (resizable). 
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char ** argv) {
    std::vector<int> v;
    for (int i=1; i<=13; i++)
        v.push_back(i);

    for (auto j : v)
        std::cout << j << " ";
    std::cout << std::endl;

    // Vectors can be indexed
    std::cout << "8th number is: " << v[7] << std::endl;

    // Their size is easy to find
    std::cout << "Vector size is: " << v.size() << std::endl;

    // New items can be easily added
    v.push_back(165);

    for (auto j : v)
        std::cout << j << " ";
    std::cout << std::endl;

    std::cout << "Front elem: " << v.front() << std::endl;
    std::cout << "Back elem:  " << v.back() << std::endl;

    return 0;
}