// Author: Stéphane Dorotich
// CPSC 457
// Use freely

#include <iomanip>
#include <iostream>
#include <vector>

struct Graph {
    std::vector<std::vector<int>> adj_list;
    std::vector<int> terminating_nodes;
    std::vector<int> in_counts;
    
    // Constructor
    Graph (int n) {
        adj_list.resize(n);
        in_counts.resize(n);
        terminating_nodes = std::vector<int>();
        // Fill adj_list with n empty vectors
        std::fill(adj_list.begin(), adj_list.end(), std::vector<int>());
        // Fill in_counts with n 0s
        std::fill(in_counts.begin(), in_counts.end(), 0);
    }

    void display() {
        std::cout << " Adj_list:\n";
        for (size_t i = 0; i < adj_list.size(); i++) {
            std::cout << "\t" << i << ":\t";
            for (int node : adj_list[i])
                std::cout << node << ", ";
            std::cout << std::endl;
        }

        std::cout << " In_count:\n";
        for (size_t i = 0; i < in_counts.size(); i++)
            std::cout << "\t" << i << ":\t" << in_counts[i] << std::endl;
    }

    void pretty_display() {
        std::cout << std::setw(7) << std::left << "Node";
        std::cout << std::setw(13) << std::left << "In_count";
        std::cout << "Adj_list\n";
        for (size_t i = 0; i < adj_list.size(); i++) {
            std::cout << std::setw(7) << i;
            std::cout << std::setw(13) << in_counts[i];
            std::cout << "[";
            for (int node : adj_list[i])
                std::cout << node << ", ";
            std::cout << "]\n";
        }

        std::cout << std::endl << std::setw(20) << "Terminating nodes:";
        std::cout << "[";
        for (int v : terminating_nodes)
            std::cout << v << ", ";
        std::cout << "]\n\n";
    }
};

void build_graph(Graph & g, std::vector<int> & FAT) {
    // TASK: build a graph such that
    // for each element of FAT
    //  there is an outgoing edge from the node denoted by the index
    //  to the node denoted by the value.
    //  e.g.
    //      if   FAT[7] = 13
    //      then     7 -> 13
    
    // populate the adj_list (a node's adj_list stores its incoming edges)
    // populate the in_counts
}

void find_files(std::vector<int> & FAT) {
    Graph g = Graph(FAT.size());
    build_graph(g, FAT);
    g.pretty_display();
    std::cout << "There are " << g.terminating_nodes.size() << " terminating nodes.\n";   
}

int main(int argc, char ** argv) {
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

    find_files(FAT);
}