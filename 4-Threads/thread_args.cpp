// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <pthread.h>
#include <unistd.h>

#define N_THREADS 4

void * routine(void * ptr) {
    int arg = *(int *) ptr;
    arg += 1000;
    return NULL;
}

int main() {
    pthread_t th[N_THREADS];
    int arg[N_THREADS] = {0,13,21,144};

    for (int i = 0; i < N_THREADS; i++) {
        if (pthread_create(&th[i], NULL, &routine, &arg[i]) != 0) return -1;
    }

    for (int i = 0; i < N_THREADS; i++) {
        if (pthread_join(th[i], NULL) != 0) return -1;
    }

    for (int i = 0; i < N_THREADS; i++) {
        std::cout << "arg[" << i << "]: " << arg[i] << std::endl; 
    }
    return 0;
}