#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Process ID:\t\t" << getpid() << std::endl;
    std::cout << "Parent Process ID:\t" << getppid() << std::endl;
    return 0;
}