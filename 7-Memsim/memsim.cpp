/// -------------------------------------------------------------------------------------
/// this is the only file you need to edit
/// -------------------------------------------------------------------------------------
///
/// (c) 2022, Pavol Federl, pfederl@ucalgary.ca
/// Do not distribute this file.

#include "memsim.h"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <list>
// #include <unordered_map> // Step 2
// #include <set> // Step 3

#define SPACES 20

struct Partition {
  int tag;
  int64_t size, addr;
};

typedef std::list<Partition>::iterator PartitionRef;

struct scmp {
  bool operator()(const PartitionRef & c1, const PartitionRef & c2) const {
    if (c1->size == c2->size)
      return c1->addr < c2->addr;
    else return c1->size > c2->size;
  }
};

// I recommend you implement the simulator as a class. This is only a suggestion.
// If you decide not to use this class, feel free to remove it.
struct Simulator {
  MemSimResult result;
  int64_t page_size;
  uint32_t debug_i = 0; // used while checking consistency

  // Step 1
  // all partitions, in a linked list
  std::list<Partition> all_blocks;
  
  // // Step 2
  // // quick access to all tagged partitions
  // std::unordered_map<long, std::vector<PartitionRef>> tagged_blocks;
  
  // // Step 3
  // // sorted partitions by size/address
  // std::set<PartitionRef,scmp> free_blocks;


  Simulator(int64_t page_size)
  {
    // constructor
    page_size = page_size;
    result.n_pages_requested = 0;
  }

  PartitionRef get_largest_free_block(int size) {
    // Good for Step 1
    // Good for Step 2
    // Update for Step 3

    // - search through the list of partitions from start to end, and
    //   find the largest partition that fits requested size
    //     - in case of ties, pick the first partition found
    // - if no suitable partition found:
    //     - return all_blocks.end()

    // Good for Step 1
    // Good for Step 2
    // Update for Step 3
    for (PartitionRef it = all_blocks.begin(); it != all_blocks.end(); it=std::next(it)) {
      // find largest free block
    }

    // if no blocks found || largest free block is too small for request
    return all_blocks.end();
    // otherwise, return largest free block
  }

  PartitionRef create_new_block(int size) {
    // Good for Step 1
    // Good for Step 2
    // Update for Step 3

    // - if no suitable partition found:
    //     - get minimum number of pages from OS, but consider the
    //       case when last partition is free
    //     - add the new memory at the end of partition list
    //     - the last partition will be the best partition
    return std::prev(all_blocks.end()); // correct
  }

  void free_and_merge(PartitionRef p) {
    // Good for Step 1
    // Good for Step 2
    // Update for Step 3

    //         - mark the partition free (use tag of -1)
    // one line

    //         - merge any adjacent free partitions
  
    // if left neighbour (l.n.) is free
    //    absorb p into l.n.
    // if right neighbour (r.n.) is free
    //    absorb r.n. into p
    
    // ! This is the hardest part of the assignment.
    // ! Do this ON PAPER FIRST
    // ! If you understand it on paper, it is easy to implement.
    // ! PLEASE PLEASE PLEASE do this on paper first

    // use erase() from cpp list
    // note: the erase() method returns an Iterator to the node 
    // after the erased one, this can be used to your advantage
  }

  void allocate(int tag, int size)
  {
    // Good for Step 1
    // Good for Step 2
    // Good for Step 3
    PartitionRef p = get_largest_free_block(size);
    if (p == all_blocks.end()) // no suitable partition found, create a new block
      p = create_new_block(size);
        
    // Update for Step 1
    // Update for Step 2
    // Update for Step 3
    // - split the best partition in two if necessary
    //     - mark the first partition occupied, and store the tag in it
    //     - mark the second partition free

    // Use insert() from cpp list
  }

  void deallocate(int tag)
  {
    // Good for Step 1
    // Update for Step 2
    // Update for Step 3  
    for (PartitionRef it = all_blocks.begin(); it != all_blocks.end(); it=std::next(it)) {
      if ((*it).tag == tag) free_and_merge(it);
    }
  }

  MemSimResult getStats()
  {
    // // Get largest_free_partition_size
    // // Get largest_free_partition_address

    // result.largest_free_partition_size = ???
    // result.largest_free_partition_address = ???

    return result;
  }
  void check_consistency()
  {
    // mem_sim() calls this after every request to make sure all data structures
    // are consistent. Since this will probablly slow down your code, you should
    // disable comment out the call below before submitting your code for grading.
    check_consistency_internal();
  }
  void check_consistency_internal()
  {
    std::cout << "\nIteration<" << debug_i++ << "> =======================================================\n";
        
    // you do not need to implement this method at all - this is just my suggestion
    // to help you with debugging

    // here are some suggestions for consistency checks (see appendix also):

    // make sure the sum of all partition sizes in your linked list is
    // the same as number of page requests * page_size
    int64_t total_size = 0;
    for (PartitionRef it = all_blocks.begin(); it != all_blocks.end(); it=std::next(it)) {
      total_size+= (*it).size;
    }
    int64_t expected_size = result.n_pages_requested * page_size;

    std::cout << std::setw(SPACES) << std::right << "Total Size: ";
    
    if (total_size == expected_size) {
      std::cout << "Pass\n";
    } else {
      std::cout << "Fail\n";
      std::cout << "\t\tExpected: " << expected_size << std::endl;
      std::cout << "\t\tActual:   " << total_size << std::endl;
    }

    // make sure your addresses are correct
    int64_t addr = 0;
    int64_t id = 0;
    std::cout << std::setw(SPACES) << std::right << "Addresses: ";
    for (PartitionRef it = all_blocks.begin(); it != all_blocks.end(); it=std::next(it)) {
      if ((*it).addr != addr) {
        std::cout << "Fail\n";
        std::cout << "\t\tBlock:    " << id << std::endl;
        std::cout << "\t\tExpected: " << addr+(*it).size << std::endl;
        std::cout << "\t\tActual:   " << (*it).addr << std::endl;
        id = -1;
        break;
      }
      id++;
      addr+=(*it).size;
    }
    if (id != -1) std::cout << "Pass\n";

    // make sure the number of all partitions in your tag data structure +
    // number of partitions in your free blocks is the same as the size
    // of the linked list

    // make sure that every free partition is in free blocks

    // make sure that every partition in free_blocks is actually free

    // make sure that none of the partition sizes or addresses are < 1
    std::cout << std::setw(SPACES) << std::right << "Ss and As (+): ";
    id = 0;
    for (PartitionRef it = all_blocks.begin(); it != all_blocks.end(); it=std::next(it)) {
      if ((*it).size < 1 || (*it).addr < 1) {
        std::cout << "Fail\n";
        std::cout << "\t\tBlock:    " << id << std::endl;
        std::cout << "\t\tSize:     " << (*it).size << std::endl;
        std::cout << "\t\tAddress:  " << (*it).addr << std::endl;
        id = -1;
      }
      id++;
    }
    if (id != -1)
      std::cout << "Pass\n";
  }
};

// re-implement the following function
// ===================================
// parameters:
//    page_size: integer in range [1..1,000,000]
//    requests: array of requests
// return:
//    some statistics at the end of simulation
MemSimResult mem_sim(int64_t page_size, const std::vector<Request> & requests)
{
  // if you decide to use the simulator class above, you probably do not need
  // to modify below at all
  Simulator sim(page_size);
  for (const auto & req : requests) {
    if (req.tag < 0) {
      sim.deallocate(-req.tag);
    } else {
      sim.allocate(req.tag, req.size);
    }
    sim.check_consistency();
  }
  return sim.getStats();
}
