#include <iostream>

void usage_error(char * prog) {
    std::cout << "Usage:\n\t" << prog << " argv1\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc == 1) usage_error(argv[0]);

    for (int i = 0; i < argc; i++) {
        std::cout << argv[0] << std::endl;
    }
}