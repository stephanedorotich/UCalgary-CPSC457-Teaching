// Author: Stephane Dorotich
// CPSC 457

#include <iostream>
#include <list>
#include <vector>

struct Partition {
	int id;
	int size;
};

typedef std::list<Partition>::iterator PartitionRef;

int main(int argc, char ** argv) {
	std::list<struct Partition> all_blocks;

	// Lists in cpp are Doubly-Linked Lists

	// They have constant time insert/remove on Front/Back
	all_blocks.push_back({7, 121});
	all_blocks.push_back({13, 1500});
	
	all_blocks.push_front({17, 35});

	// They can be iterated through in a variety of ways (a "for auto" loop will do the trick)
	// Formally, however, ITERATORS should be used.

	std::cout << "Iteration<1> ========================================================\n";
	for (std::list<Partition>::iterator it = all_blocks.begin(); it != all_blocks.end(); it=std::next(it)) {
		std::cout << "\tid: " << (*it).id << "\tsize: " << (*it).size << std::endl;
	}

	// Iterators are pointers to elements inside of structures.
	// They can be de-referenced (as above) to access the value stored at that location

	// Cpp provides standard iterators for all containers (list, set, unordered_map, vector)

	// you can search "cpp vector", "cpp list", "cpp unordered_map", they all have a begin() method
	// the begin() method returns an iterator to the first element.

	// Creating iterators is rather verbose, as in the case above:
	//		std::list<ObjectInList>::iterator
	// You can use typedef (as above) to shorthand a name for the iterator.

	std::cout << "\nIteration<2> ========================================================\n";
	for (PartitionRef it = all_blocks.begin(); it != all_blocks.end(); it=std::next(it)) {
		std::cout << "\tid: " << (*it).id << "\tsize: " << (*it).size << std::endl;
		// Lists support constant time insertion anywhere in a list
	}

	// The .end() iterator of a container is "non-existent" it's essentially beyond a list
	// list =    7   ->   2   ->   4   ->
	//			 |      					|           
	//        .begin()					  .end()


	// Iterators can be used for constant time access to elements inside a container
	std::vector<PartitionRef> quick_access;

	for (PartitionRef it = all_blocks.begin(); it != all_blocks.end(); it=std::next(it)) {
		quick_access.push_back(it);
	}

	// Lists support constant time insertion/deletion anywhere in the list using
	// the insert & erase methods, which both take an iterator as an argument

	all_blocks.insert(quick_access[1], {4, 16}); // insert {4, 16} before {7, 121}
	all_blocks.insert(quick_access[1], {15, 225}); // insert {15, 225} before {7, 121}
	all_blocks.erase(quick_access[1]); // remove {7, 121}

	std::cout << "\nIteration<3> ========================================================\n";
	for (PartitionRef it = all_blocks.begin(); it != all_blocks.end(); it=std::next(it)) {
		std::cout << "\tid: " << (*it).id << "\tsize: " << (*it).size << std::endl;
	}
}
