// Author: Stéphane Dorotich
// CPSC 457
// Use freely

#include <iostream>
#include <unistd.h>
#include <cstring>

#define BUFFER_SIZE 1024

int main() {
    // Create buffer for reading stream contents
    char buffer[BUFFER_SIZE];

    // Create variable for storing number of bytes read
    size_t nbytes;

    // Number of calls to read
    int64_t total_reads = 0;

    // Count newlines in input
    int64_t newlines_count = 0;


    // While there is input to be read, read
    while ((nbytes = read(0, buffer, BUFFER_SIZE)) > 0) {
        // 0 is the file descriptor for Standard Input.         STDIN_FILENO
        // 1 is the file descriptor for Standard Output.        STDOUT_FILENO
        // 2 is the file descriptor for Standard Error.         STDERR_FILENO

        // std::cout << nbytes << std::endl; // Print number of bytes read
        total_reads++;
        // Scan buffer for newline chars
        for (int i = 0; i < nbytes; i++)
            if ((char) buffer[i] == '\n') newlines_count++;\

        // Clear buffer
        memset(buffer, 0, nbytes);
    }

    std::cout << total_reads << " total reads\n";
    std::cout << newlines_count << " new line characters '\\n'\n";
    return 0;
}
