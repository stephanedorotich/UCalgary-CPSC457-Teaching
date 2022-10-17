#include <iostream>

void usage_error(const char * pname) {
    std::cout << "Usage\n\t" << pname << " n_threads\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);
    int n_threads = atoi(argv[1]);
    if (n_threads == 0) usage_error(argv[0]);

    std::cout << "Starting " << n_threads << " threads\n";
}