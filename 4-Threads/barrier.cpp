#include <iostream>

#define NTHREADS 3

pthread_barrier_t barrier;

struct targ {
    int id;
};

void * routine(void * ptr) {
    struct targ & data = *(struct targ *) ptr;
    for (int i = 0; i < 5; i++) {
        if(pthread_barrier_wait(&barrier)){
            // SERIAL ===============================================================
            std::cout << "Thread   " << data.id << "   in serial section\n";
            // ======================================================================
        }
        pthread_barrier_wait(&barrier);
        // PARALLEL ============================================================

        // =====================================================================
    }
    return NULL;
}

int main() {
    pthread_t th[NTHREADS];
    struct targ data[NTHREADS];
    pthread_barrier_init(&barrier, NULL, NTHREADS);

    for (int i = 0; i < NTHREADS; i++) {
        data[i].id = i;
        pthread_create(&th[i], NULL, &routine, &data[i]);
    }

    for (int i = 0; i < NTHREADS; i++) {
        pthread_join(th[i], NULL);
    }

    pthread_barrier_destroy(&barrier);
}
