#include <iostream>
#include <sys/stat.h>
#include <sys/sysmacros.h>

void usage_error(char * progName) {
    std::cout << "Usage:\n\t" << progName << " path\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);
    struct stat s;
    stat(argv[1], &s);

    // Finding out if the pathname is a directory or regular file
    std::cout << "\nIs it a Directory or a file?\n";
    std::cout << "Is dir:\t" << S_ISDIR(s.st_mode) << std::endl;
    std::cout << "Is reg:\t" << S_ISREG(s.st_mode) << std::endl;

    // What is the file's Inode number?
    std::cout << "\nWhat is the file's Inode number?\n";
    std::cout << "Inode:\t" << s.st_ino << std::endl;

    // On what device does this file reside?
    std::cout << "\nOn what device does this file exist?\n";
    std::cout << "Device:\t" << s.st_dev << std::endl;

    // How many bytes is the file?
    std::cout << "\nHow many bytes is the file?\n";
    std::cout << "Bytes:\t" << s.st_size << std::endl;
}