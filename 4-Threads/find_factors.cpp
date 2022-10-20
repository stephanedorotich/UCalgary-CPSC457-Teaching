#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
/*
This program displays every factor pair of each integer from 1 to N.
Additionally, any integer that has more than 4 factor pairs is added to a vector
*/

void usage_error(const char * pname) {
    std::cout << "Usage:\n\t" << pname << " n threshold\twhere n is a positive integer.\n";
    exit(-1);
}

void display_factor_pairs(const uint64_t & num, const std::vector<std::pair<uint64_t, uint64_t>> & factor_pairs) {
    // Display all factor pairs of number
    std::cout << num << ":";
    for (const auto & fp : factor_pairs) {
        printf(" (%ld, %ld)", fp.first, fp.second);
    }
    std::cout << std::endl;
}

int main(int argc, char ** argv) {
    if (argc != 3) usage_error(argv[0]);
    uint64_t n = atoi(argv[1]);
    uint64_t x = atoi(argv[2]);
    if (n == 0 || x == 0) usage_error(argv[0]);

    std::vector<uint64_t> nums_with_x_fp;
    std::vector<std::pair<uint64_t, uint64_t>> factor_pairs;
    for (uint64_t number = 1; number <= n; number++) {
        factor_pairs.clear(); // clear vector
        uint64_t limit = sqrt(number);

        for (int factor = 1; factor <= limit; factor++)
            if (number % factor == 0)
                factor_pairs.push_back({factor, number / factor});

        // display_factor_pairs(number, factor_pairs);
        if (factor_pairs.size() >= x)
            nums_with_x_fp.push_back(number);
    }

    // std::vector<uint64_t> res;
    // res.insert(std::end(res), std::begin(a), std::end(a));

    for (uint64_t i : nums_with_x_fp)
        std::cout << i << ", ";
    std::cout << std::endl;
}