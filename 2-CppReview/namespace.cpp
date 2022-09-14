// Author: Stéphane Dorotich
// CPSC457
// Use freely

#include <iostream>

namespace Planet {
    void jupiter() {
        std::cout << "Jupiter is a gas-giant planet and the largest in our solar system.\n";
        std::cout << "There are 75 moons orbiting Jupiter.\n";
    }
}

namespace RomanGods {
    void jupiter() {
        std::cout << "Jupiter is the Roman god of Sky and Thunder ";
        std::cout << "and is considered\nthe chief deity in the Roman pantheon\n";
    }
}

int main() {
    RomanGods::jupiter();
}