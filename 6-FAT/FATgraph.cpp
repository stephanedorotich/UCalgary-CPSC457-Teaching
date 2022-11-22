// Author: Stéphane Dorotich
// CPSC 457
// Use freely

#include <iostream>
#include <vector>
#include <climits>

struct Result {
    int num_terminating_nodes;

    void print() {
        std::cout << "There are " << num_terminating_nodes << " terminating files.\n";
    }
};

struct Graph {
    std::vector<int> adj_list;
    std::vector<int> in_counts;
};

void build_graph(Graph g, std::vector<int> & FAT) {
    // TASK: build a graph such that
    // for each element of FAT
    //  there is an outgoing edge from the node denoted by the index
    //  to the node denoted by the value.
    //  e.g.
    //      if   FAT[7] = 13
    //      then     7 -> 13
    
    g.adj_list = std::vector<int>(FAT.size()); // *will need to change this*
    g.in_counts = std::vector<int>(FAT.size()); // *will need to change this too*

    // populate the adj_list (a node's adj_list stores its incoming edges)
    // populate the in_counts
}

void find_files(std::vector<int> & FAT, Result result) {
    Graph g;
    build_graph(g, FAT);

    // result.num_terminating_nodes = ?
    return;
}

int main(int argc, char ** argv) {
    Result result;
    result.num_terminating_nodes = INT_MAX;
    std::vector<int> FAT;

    for (std::string line; std::getline(std::cin, line); ) {
        try {
            FAT.push_back(std::stoi(line));
        } catch (std::invalid_argument & ex) {
            std::cout << "Malformed input <" << line << ">. Integers expected.\n";
            std::cout << "Aborting program...\n";
            exit(-1);
        }
    }

    find_files(FAT, result);
    result.print();
}