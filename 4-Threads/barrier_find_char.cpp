#include <iostream>
#include <atomic>
#include <unistd.h>
#include <cstring>

#define NTHREADS 8
#define BUFFSIZE 1024*1024

pthread_barrier_t barrier;
std::atomic<bool> done;
char buffer[1024*1024];
ssize_t num_bytes;
int num_reads = 0;

struct targ {
    int id;
    int n_threads;
    char c;
    uint64_t count;
};

void * routine(void * ptr) {
    struct targ & data = *(struct targ *) ptr;

    int start_index, end_index;
    uint64_t count = 0;

    while (!done) {
        if(pthread_barrier_wait(&barrier)) {
            // SERIAL ====================================================================
            std::cout << "Read " << num_reads++ << "\t\t\tthread " << data.id << std::endl;
            num_bytes = read(0, &buffer, BUFFSIZE); // read from stdin to buffer
            if (num_bytes == 0) done.store(true); // nothing to read
            // ===========================================================================
        }
        pthread_barrier_wait(&barrier);
        // PARALLEL =================================================================
        start_index = (num_bytes / data.n_threads) * data.id;
        if (data.id+1 == data.n_threads) end_index = num_bytes; // last thread gets more work
        else end_index = (num_bytes / data.n_threads) * (data.id + 1);

        for (int i = start_index; i < end_index; i++)
            if (buffer[i] == data.c) count++;
        // ==========================================================================
    }
    data.count = count;
    return NULL;
}

void usage_error(const char * progName) {
    std::cout << "Usage:\n\t" << progName << " c\n";
    std::cout << "\tWhere c is a single character\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);
    if (strlen(argv[1]) != 1) usage_error(argv[0]);
    char c = argv[1][0];

    done.store(false);

    pthread_t th[NTHREADS];
    struct targ data[NTHREADS];

    pthread_barrier_init(&barrier, NULL, NTHREADS);

    for (int i = 0; i < NTHREADS; i++) {
        data[i].id = i;
        data[i].n_threads = NTHREADS;
        data[i].c = c;
        pthread_create(&th[i], NULL, &routine, &data[i]);
    }

    uint64_t total_count = 0;
    for (int i = 0; i < NTHREADS; i++) {
        pthread_join(th[i], NULL);
        total_count+=data[i].count;
    }

    pthread_barrier_destroy(&barrier);

    std::cout << "Found " << total_count << " <" << c << ">'s!\n";
}