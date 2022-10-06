// Author: Stéphane Dorotich
// CPSC 457
// Use freely

// Write a program that:
//  - computes the total size of files in a directory (number of bytes)
//  - print to stdout the total size
//  - print to stdout the largest file. (filename: size)

// Challenge:
//  - Recur into subdirectories. If the specified directory contains directory types,
//    open them up and scan their files also.

#include <iostream>
#include <sys/stat.h>
#include <dirent.h>

void usage_error(const char * progName) {
    std::cout << "Usage:\n\t" << progName << " dir\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);

    DIR * dirp = opendir(argv[1]);
    if (dirp == NULL) usage_error(argv[0]);

    struct dirent * dent; // directory entry
    
    while ((dent = readdir(dirp)) != NULL) {
        std::cout << dent->d_name << std::endl;
    }

    closedir(dirp);
}