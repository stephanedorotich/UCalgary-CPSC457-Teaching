// Author: Stéphane Dorotich
// CPSC 457
// Use freely

#include <cstring>
#include <iostream>
#include <pthread.h>
#include <time.h>

struct tdata {
    std::string name;
    int age;
    int lucky_number; // this data value will be set by the thread
};

void * routine(void * ptr) {
    struct tdata * me = (struct tdata *) ptr;
    me->lucky_number = (rand() % 100);
    return NULL;
}

void usage_error(const char * pname) {
    std::cout << "Usage:\n\t" << pname << " name age\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 3) usage_error(-1);

    // Set up structure with data for thread.
    struct tdata me;
    me.name = argv[1];
    me.age = atoi(argv[2]);

    srand(time(NULL)); // seed srand


    pthread_t t1; // create a single thread
    if (pthread_create(&t1, NULL, &routine, &me) != 0) return -1;
    if (pthread_join(t1, NULL) != 0) return -1;

    std::cout << "Hello " << me.name << std::endl;
    std::cout << "Your lucky number is: " << me.lucky_number << std::endl;
    return 0;
}