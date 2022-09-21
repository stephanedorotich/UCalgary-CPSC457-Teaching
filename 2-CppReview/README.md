---
title: 2-CppReview
author: Stéphane Dorotich
---

## Objectives

Get comfortable writing basic C++ programs. Review fundamental programming principles/basics.
- Review the basics of C++ programming
- Live coding demos
- Student practice

This module contains MANY small code files. The purpose is to provide
a broad overview of a variety of C++ features.

## Concepts

- basic syntax
- compiler warnings
- integer types
- standard output
- structures
- global variables
- pointers vs. references
- namespaces
- strings vs. char arrays

## 1. Pull Code Base
- Open Ubuntu (or preferred prompt) and ```ssh first.last@linuxlab.cpsc.ucalgary.ca```
- ```git pull``` or ```git clone https://github.com/stephanedorotich/t457```
- Navigate to ```t457/2-CppReview```

## 2. Review Basic Syntax and Program Args

### Exercise 0: HelloWorld
***
- ```nano/vi/vim/pico hello.cpp```
- Code a hello world program.
- Use either C++ streams (```std::cout << ...```) or C ```printf()```. You will need ```#include <iostream>``` and ```#include <cstdio>``` respectively.
- Compile and run

### Exercise 1: Program Args (Activity)
***
- Review program args (what are they, why are they useful, ...)
  - argc = argument count
  - argv = argument vector
- Task students to modify hello so that it:
  - Print ```argv[1]```
  - What is a problem? Exceptions!!! Talk about that :)
  - Verify that there is at least 1 arg. Exit code if not.
  - Prints the # of args
  - Using a loop, print each argument

### Exercise 2: Fixing Syntax Errors
***
Open VS Code and remote in to 457 folder.

- Launch VS Code
- Ctrl + Shift + P (to open up Command Palette)
- Type "Remote - SSH" to establish connection to University Servers
- Download VS Code remote server

```1-syntax.cpp``` and ```2-syntax.cpp``` will not compile. Fix the syntax errors.

## 3. Review Core Concepts

### Exercise 0: Review Integer Types
***
- Review ```ints.cpp``` as a class.
- Understand difference between ```short, int, long, int64_t, etc.```

### Exercise 1: Review Printing to Standard Output
***
- Review ```stdio_cout.cpp``` and ```stdio_printf```
- Using ```std::cout``` leverages C++ streams. (preferred)
- Using ```printf()``` leverages C libraries.

### Exercise 2: Structures
***
- Review ```person.cpp```
- Compile and execute.
- Understand that structures can be used to "package" data together.

### Exercise 3: Global Variables
***
- Review ```global_vars.cpp```
- Understand the difference (and persistance) of global vs. local variables

### Exercise 4: Pointers vs. References
***
- Review ```pointers_vs_references.cpp```
- Compile and execute.
- Understand that references are "static" references to a particular object. Once created, they cannot be made to reference something else.
- Understand that pointers refer to locations in memory where data is stored.

### Exercise 5: Pass by Reference vs. Pass by Value
***
- Review ```pythagorean.cpp```
- Understand that pass by reference is MUCH MORE SPACE efficient.

### Exercise 6: Vectors
***
- Review ```vector.cpp```
- Discuss danger of using ```auto``` instead of being deliberate about data type.
- C++ documentation <https://en.cppreference.com/w/cpp/container/vector>
- Review ```vec_loops.cpp```
- Discuss the variety of implementations and their benefits and drawbacks.
- Again, warn against ```auto```. Should ALWAYS know your data type.


### Exercise 7: Namespace (optn)
***
- Review ```namespace.cpp```
- Understand how namespaces can be used to "package" related methods.
- Namespaces are used to avoid naming collisions.
- ```using namespace std``` is an option, but not recommended as it reduces code clarity.

### Exercise 8: String vs. Char Array
***
- Review ```string.cpp```
- Understand that char arrays are immutable
- Understand that ```std::string``` are feature rich.
- C++ documentation <https://cplusplus.com/reference/string/string/>

### Exercise 9: Enumerators
***
- Review ```enumerator.cpp```
- Observe that enum's just create aliases for numbers
- Observe that switch statements are compact if-else structures
- Observe the need for break statements