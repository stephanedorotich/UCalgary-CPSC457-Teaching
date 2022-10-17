#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
/*
This program displays every factor pair of each integer from 1 to N.
*/

void usage_error(const char * pname) {
    std::cout << "Usage:\n\t" << pname << " n\twhere n is a positive integer.\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);
    uint64_t n = atoi(argv[1]);
    if (n == 0) usage_error(argv[0]);

    std::vector<std::pair<uint64_t, uint64_t>> factor_pairs;
    for (uint64_t number = 1; number <= n; number++) {
        // Find all factor pairs of number
        factor_pairs.clear(); // clear the vector of pairs
        uint64_t limit = sqrt(number);

        for (int factor = 1; factor <= limit; factor++)
            if (number % factor == 0)
                factor_pairs.push_back({factor, number / factor});

        // Display all factor pairs of number
        std::cout << number << ":";
        for (const auto & fp : factor_pairs) {
            printf(" (%ld, %ld)", fp.first, fp.second);
        }
        std::cout << std::endl;
    }
}