// Author: Stéphane Dorotich
// CPSC 457
// Use freely

#include <cstdio>
#include <iostream>
#include <cstring>
#include <unordered_map>

#define BSIZE 1024


void count_file_types(std::string dirname)
{
    std::string command = "file -b " + dirname + "/*";
    FILE * fp = popen(command.c_str(), "r");
    char buff[BSIZE];

    std::unordered_map<std::string, int> res;
    std::string temp;
    int i;

    while (fgets(buff, BSIZE, fp) != NULL) {
        // For each entry, keep only the values BEFORE the first ','
        i = 0;
        while (i < strlen(buff) && buff[i] != ',') i++;
        if (i == strlen(buff)) i--;
        temp.assign(buff, 0, i);

        // If filetype is new, add to dictionary
        if (res.count(temp) == 0)
            res[temp] = 1;
        // Else, increment count of filetype
        else res[temp]++;
    }
    pclose(fp);

    // Display all counts of filetypes
    // Can use: const auto & p
    //      Just remember that unordered maps store values as PAIRS
    for (const std::pair<std::string, int> & p : res)
        std::cout << p.first << ": " << p.second << std::endl;
}

void list_directory_contents(std::string dirname)
{
    std::string command = "ls -l " + dirname;
    FILE * fp = popen(command.c_str(), "r");
    char buff[BSIZE];
    while (fgets(buff, BSIZE, fp) != NULL) {
        std::cout << buff;
    }
    pclose(fp);
}

void determine_file_types(std::string dirname)
{
    std::string command = "file -b " + dirname + "/*";
    FILE * fp = popen(command.c_str(), "r");
    char buff[BSIZE];
    while (fgets(buff, BSIZE, fp) != NULL) {
        std::cout << buff;
    }
    pclose(fp);
}

int main () {
    std::string dirname;
    std::cout << "Please enter a directory: ";
    std::cin >> dirname;

    // list_directory_contents(dirname);
    // determine_file_types(dirname);
    count_file_types(dirname);
}