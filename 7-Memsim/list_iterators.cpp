#include <iostream>
#include <list>

typedef std::list<int>::iterator Iter;

void print_list(std::list<int> & list) {
    for (Iter it = list.begin(); it != list.end(); it=std::next(it))
        std::cout << (*it) << ", ";
    std::cout << std::endl;
}

void version_1 (std::list<int> list) {
    std::cout << "Version 1 =======================================\n";
    // This method has a problem...
    for (Iter it = list.begin(); it != list.end(); it=std::next(it)) {
        if ((*it) % 3 != 0)
            list.erase(it);
    }

    print_list(list);
}

void version_2(std::list<int> list) {
    std::cout << "Version 2 =======================================\n";
    Iter it, next;
    for (it = list.begin(); it != list.end(); ) {
        next = std::next(it);
        if ((*it) % 3 != 0) list.erase(it);
        it = next;
    }

    print_list(list);
}

void version_3(std::list<int> list) {
    std::cout << "Version 3 =======================================\n";
    Iter it, next;
    it = list.begin();
    while (it != list.end()) {
        next = std::next(it);
        if ((*it) % 3 != 0) list.erase(it);
        it = next;
    }

    print_list(list);
}

void usage_error(const char * progName) {
    std::cout << "Usage:\n\t" << progName << " i\t\ti is one of [1, 2, 3]\n";
    exit(-1);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);
    int version = atoi(argv[1]);
    if (version < 1 || version > 3) usage_error(argv[0]);

    std::list<int> list;

    // Push 0 to 19 to list
    for (int i = 0; i < 20; i++)
        list.push_back(i);

    // Remove all elements that are divisible by 3
    switch (version) {
        case 1:
            version_1(list);
            break;
        case 2:
            version_2(list);
            break;
        case 3:
            version_3(list);
            break;
    }
}
