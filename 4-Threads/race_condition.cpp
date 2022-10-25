// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <pthread.h>

uint64_t x = 0;

struct targ {
    uint64_t n;
};

void * routine(void * ptr) {
    struct targ & data = *(struct targ *) ptr;
    for (int i = 0; i < data.n; i++) {
        x++;
    }
    return NULL;
}

void usage_error(const char * progName) {
    std::cout << "Usage:\n\t" << progName << " n n_threads\n";
    std::cout << "   where 0 < n_threads <= 256\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 3) usage_error(argv[0]);
    int64_t n = atol(argv[1]);
    int n_threads = atoi(argv[2]);
    if (n == 0 || n_threads == 0 || n_threads > 256) usage_error(argv[0]);

    pthread_t th[n_threads];
    struct targ data[n_threads];

    // Create threads
    for (int i = 0; i < n_threads; i++) {
        data[i].n = n;
        if (0 != pthread_create(&th[i], NULL, &routine, &data[i])) std::cout << "Error creating thread " << i << std::endl;
    }

    // Join threads
    for (int i = 0; i < n_threads; i++) {
        if (0 != pthread_join(th[i], NULL)) std::cout << "Error joining thread " << i << std::endl;
    }

    std::cout << "Value of x: " << x << std::endl;
    return 0;
}