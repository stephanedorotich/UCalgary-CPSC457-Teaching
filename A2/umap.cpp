#include <iostream>
#include <unordered_map>

void usage_error(std::string pname) {
    std::cout << "Usage:\n\t" << pname << " N" << std::endl;
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);

    std::unordered_map<std::string, int> map;

    // Adding new values
    map["some key value"] = 7;
    map["apples"] = 2;
    
    // iterating through a map
    for (auto w : map) {
        // How do we print out the values?
        std::cout << w << std::endl;
    }

    // Checking if a key exists using .count()
    std::cout << "Contains apples:  " << map.count("apples") << std::endl;
    std::cout << "Contains oranges: " << map.count("oranges") << std::endl;

    // Accessing value stored at key
    std::cout << "apples occurs " << map["apples"] << " times" << std::endl;
}
