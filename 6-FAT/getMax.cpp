#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>

int get_depth(int n) {
    srand(n);
    return rand() % 1000;
}

void find_max_depth_for_each_list(std::vector<std::vector<int>> lists) {
    // for each list
    //      find its max depth and print it
    // ex. "List<0> max_depth: 271"

    int list_index = 0;
    int node_index = 0;
    get_depth(lists[list_index][node_index]);
}

void load_vector_from_stdin(std::vector<std::vector<int>> & v, int num_lists) {
    int i = 0;
    for (std::string line; std::getline(std::cin, line); ) {
        try {
            v[i++ % num_lists].push_back(std::stoi(line));
        } catch (std::invalid_argument & ex) {
            std::cout << "Malformed input <" << line << ">. Integers expected.\n";
            std::cout << "Aborting program...\n";
            exit(-1);
        }
    }
}

void usage_error(const char * progName) {
    std::cout << "Usage:\n\t";
    std::cout << progName << " num_lists\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);

    int num_lists = atoi(argv[1]);
    if (num_lists == 0) usage_error(argv[0]);

    std::vector<std::vector<int>> lists(num_lists);
    load_vector_from_stdin(lists, num_lists);

    // Debug statements for lists
    std::cout << "Num lists: " << lists.size() << std::endl;
    for (int i = 0; i < lists.size(); i++) {
        std::cout << "  List<" << i << "> size: " << lists[i].size() << std::endl;
    }

    std::cout << "\nStarting...\n\n";
    find_max_depth_for_each_list(lists);
}


