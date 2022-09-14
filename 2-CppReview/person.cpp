// Author: Xining Chen, Stephane Dorotich
// CPSC 457
// Use freely

#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
    std::string occupation;

    void print_info() {
        std::cout << "\nPersonal Info: "<< std::endl;
        std::cout << "\tName: " << name << std::endl;
        std::cout << "\tAge: " << age << std::endl;
        std::cout << "\tOccupation: " << occupation << std::endl;
    }
};

int main() {
    Person p1;
    std::string input;

    // Get name
    std::cout << "Enter your name: ";
    std::getline(std::cin, p1.name);

    // Get age
    std::cout << "Enter your age: ";
    std::getline(std::cin, input);
    try {
        p1.age = stoi(age);
    } catch (const std::invalid_argument& ex) {
        std::cerr << "\tInvalid argument: " << ex.what() << std::endl;
        p1.age = -1;
    }

    // Get occupation
    std::cout << "Enter your occupation: ";
    std::cin >> p1.occupation;

    p1.print_info();
    return 0;
}