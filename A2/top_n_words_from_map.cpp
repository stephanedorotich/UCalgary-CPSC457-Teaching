#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdlib>

std::vector<std::pair<int, char>> top_n(int n, std::unordered_map<char, int> & words) {
    // Source: https://gitlab.com/cpsc457/public/word-histogram
    // Approach 1
    // ===========
    // we put the contents of hist[] into std::vector and then sort it

    // first we place the words and counts into array (with count
    // negative to reverse the sort)
    std::vector<std::pair<int, char>> arr;
    for(auto & w : words)
        arr.emplace_back(-w.second, w.first);
    // if we have more than N entries, we'll sort partially, since
    // we only need the first N to be sorted
    if(arr.size() > size_t(n)) {
        std::partial_sort(arr.begin(), arr.begin() + n, arr.end());
        // drop all entries after the first n
        arr.resize(n);
    } else {
        std::sort(arr.begin(), arr.end());
    }

    // Now we can print the N entries
    printf("%ld most common words:\n", arr.size());
    for(auto & a : arr)
        printf("  - %c x %d\n", a.second, -a.first);

    return arr;
}

void populate_map(std::unordered_map<char, int> & umap) {
    // Generate 1000 numbers from 0-25.
    // Translate them into characters A - Z
    // Increment the count of each char in the umap
    srand(time(NULL)); // seed pseudo-random number generator
    char c;
    for (int i = 0; i < 10000; i++) {
        c = (char) (rand() % 26) + 97;
        // **************************************** //

        if (umap.count(c) == 0) { // check if c is in umap
            umap[c] = 1; // if not, add it and set count to 1
        } else umap[c]++; // if it is, increment count

        // **************************************** //
    }
}

void usage(std::string pname) {
    std::cout << "Usage:\n\t" << pname << " N\tWhere N is a positive integer.\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage(argv[0]); // check for 2 args
    int n = atoi(argv[1]);
    if (n == 0) usage(argv[0]); // check for positive integer

    std::unordered_map<char, int> word_map;
    populate_map(word_map);

    // Take top n words from map
    std::vector<std::pair<int, char>> most_common_words = top_n(n, word_map);
}