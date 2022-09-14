#include <iostream>

struct data {
    int val;

    void display() {
        std::cout << "val is:\t\t" << this->val << std::endl;
        std::cout << "address is:\t" << this << std::endl;
    }
};


// Passing by reference will send an immutable reference to the variable
// GREAT if:
//  1. You want to reduce space complexity
//  2. The caller function wants the value to be modified (eg. using structures)
void pass_by_reference(data & d) {
    d.val = 42;
    std::cout << "\nPass by reference passses the address of the original var.\n";
    d.display();
}

// Passing by value will COPY the value
// GOOD if:
//  1. value is small (in terms of storage)
//  2. original value should not be modified
void pass_by_value(data d) {
    d.val = 3544;
    std::cout << "\nPass by value creates a copy, the original var is unchanged.\n";
    d.display();
}

int main(int argc, char ** argv) {
    data d;
    d.val = 1;
    d.display();

    pass_by_reference(d);
    d.display();

    pass_by_value(d);
    d.display();
}