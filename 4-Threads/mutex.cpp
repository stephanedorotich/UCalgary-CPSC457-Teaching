// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <pthread.h>

// Write a program that:
//      - Creates two different threads
//      - One thread increments x for every even number from 1 to n (inclusive)
//      - One thread decrements x for every multiple of 3 from 1 to n (inclusive)

// Expected result:
//  from 1-100:     Value of x: 17
//  from 1-10k:     Value of x: 1667
//  from 1-10M:     Value of x: 1666667

// Question 1:
//      - Time your code with an upper bound of 10M.
//      - Time the compare program.
// Why is there such a big difference?

uint64_t x = 0;

void * routine1(void * ptr) {
    return NULL;
}

void * routine2(void * ptr) {
    return NULL;
}

void usage_error(const char * progName) {
    std::cout << "Usage\t\n" << progName << " n\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);
    int64_t n = atol(argv[1]);
    if (n == 0) usage_error(argv[0]);

    for (int64_t i = 1; i <= n; i++) {
        if (i % 2 == 0) x++;
        if (i % 3 == 0) x--;
    }

    std::cout << "Value of x: " << x << std::endl;
    return 0;
}