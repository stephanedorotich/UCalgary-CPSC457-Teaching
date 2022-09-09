# 2-CppReview

## Objectives
***
Help students get comfortable writing basic C++ programs. Remind them of some programming principles/basics. Use a combination of the following.
- Review the basics of C++ programming
- Live coding demos
- Student practice

## 1. Get Set Up
***
- Students open VS Code
- Ctrl + Shift + P (to open up Command Palette)
- Type "Remote - SSH" to establish connection to University Servers
- Open Ubuntu (or preferred prompt) and ```ssh first.last@linuxlab.cpsc.ucalgary.ca```
- Navigate to ```t457``` dir.
  - or ```git clone https://github.com/stephanedorotich/t457``` 

### Exercise 0. HelloWorld
***
- Navigate to ```t457/2-CppReview```
- ```nano/vim hello.cpp```
```
// author: My Name
#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Hello, world!\n";
}
```
You may prefer using the C library ```#include <stdio.h>``` and ```printf()``` for printing. Just be aware that virtually all coding examples in this repo use C++ streams (```std::cout << ...```)
- ```g++ hello.cpp -o hello```
- ```.hello```

### Exercise 1. Program Args (5-10min)
***
- Ask students about Program args (what are they, why are they useful, ...)
  - argc = argument count
  - argv = argument vector
- Task students to modify hello so that it:
  - Prints the # of args
  - Print ```argv[0]``` and ```argv[1]```
  - What is a problem? Exceptions!!! Talk about that :)
  - Group code a usage error method
```
int usage_error(char* programName) {
    std::cout <<"Usage:\n";
    std::cout << programName << " arg1 arg2 ...\n";
    exit(-1);
}

int main(int argc, char** argv) {
    if (argc == 1) usage_error(argv[0]);
    // ...
}
```
  - Optional: Print out all args using a for/while loop.


***
***
***
INCOMPLETE
***
***
***

### Exercise 2: Review, Fast & Furious
***

### Exercise 3: Fixing Syntax Errors
***

### Exercise 4: Fibonacci Sequence
