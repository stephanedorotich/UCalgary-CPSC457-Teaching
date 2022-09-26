// Author: Stéphane Dorotich and others
// CPSC 457
// Use freely

// Example 1: Opening a file using the open() system call wrapper.
#include <iostream>
#include <unistd.h>         // read(), close()
#include <cstring>
#include <fcntl.h>          // O_RDONLY

#define BUFFER_SIZE 1024

int main() {
    std::string input;
    std::cout << "Please enter a filename: ";
    std::cin >> input;
    const char* pathname = input.c_str();

    // Open file
    int fd = open(pathname, O_RDONLY);

    // Check for errors
    if (fd == -1) {
        std::cout << "File '" << pathname << "' does not exist!\n";
        exit(-1);
    }

    // Create buffer for reading file contents
    char buffer[BUFFER_SIZE];
    ssize_t nbytes; // store result from read call

    while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0) {
        // read stuff, print it screen
        std::cout << buffer << std::endl;
        memset(buffer, 0, sizeof(buffer)); // clear buffer
    }

    // Close file
    close(fd);

    return 0;
}
