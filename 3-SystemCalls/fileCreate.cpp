// Create and then open a file using the open() system call wrapper.
#include <iostream>
#include <unistd.h>         // read(), close()
#include <fcntl.h>
#include <cstring>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];

    // Asking for new filename
    std::cout << "Please enter a new filename: ";
    std::cin.getline(buffer, BUFFER_SIZE);

    const char * filename = buffer;

    // Check if file exists (or filename strlen is 0)
    if (strlen(filename) == 0 || access(filename, F_OK) != -1) {
        std::cout << "File '" << filename << "' already exists. Terminating program.\n";
        exit(-1);
    }

    // Open the file
    //      - Write Only & Create
    //      - User read/write permission (-rw-------)
    int fd = open(filename, O_WRONLY | O_CREAT, 0600);

    // Check that file was successfully opened
    if (fd == -1) {
        std::cout << "Failed to create new file\n";
        exit(-1);
    }

    // Ask user to input file contents
    std::cout << "Input file contents... ('done' when complete)\n";
    while (true) {
        std::cin.getline(buffer, BUFFER_SIZE);

        if (strcmp(buffer, "done") == 0) break;

        write(fd, buffer, strlen(buffer));
        write(fd, "\n", 1);
    }

    close(fd);      // Always close the file!!
    return 0;
}
