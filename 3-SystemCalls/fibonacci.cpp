// Author: Stéphane Dorotich
// CPSC 457
// Use freely

#include <iostream>

void usage_error(const char * progName) {
    std::cout << "Usage\n\t" << progName << " i\t\t Where i is the ith number of the fibonacci sequence you want to compute.\n";
    exit(-1);
}

// Credit: https://www.javatpoint.com/fibonacci-series-in-cpp
int64_t fib(int i) {
    if (i < 2) return i;
    int64_t n1 = 0, n2 = 1, n3;
    for (int n = 2; n <= i; n++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    return n3;
} 

int main(int argc, const char ** argv) {
    if (argc != 2) usage_error(argv[0]);

    try {
        int i = std::stoi(argv[1]);
        std::cout << fib(i) << std::endl;
    } catch (const std::invalid_argument & ex) {
        usage_error(argv[0]);
    }
}
