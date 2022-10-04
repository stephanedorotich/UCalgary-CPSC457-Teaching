---
title: 3-SystemCalls
author: Stéphane Dorotich
---

# Objectives

Understand the difference between User mode & Kernel mode and the cost to efficiency associated with switching between them.

Learn how to open and write to a file using system calls ```read``` and ```write```.

# Part 1: Kernel Mode vs. User Mode

Operating Systems can be abstracted into two distinct modes:

- Kernel mode: a privileged and powerful mode used by the operating system kernel
    - full access to memory and I/O
    - can read/write to storage media, remap memory, and enable/disable hardware.
    - uses a single address space
- User mode: where most user applications run
    - restricted access to memory (private address space)
    - cannot interface with hardware directly

Users work with command-line utilities and graphical user interfaces, in doing so, they make system calls which work silently in the background, interfacing with the kernel to get work done.

System calls are similar to method calls, they both accept and work on a parameter list and return values. When a system call is made, the execution of your program halts while the process switches to kernel mode. Switching between spaces is done with trap mechanism.

## Switching

To switch **from Kernel to User**:

- Load the user program onto the stack.
- Execute an instruction to load & run the program from the stack.

To switch **from User to Kernel**:

- Send an signal to the CPU (a *trap*).
- Once detected, stop execution of the program, save it's state to the stack.
- Switch to kernel mode and execute from a pre-defined memory location depending on the interrupt.

## Interrupts and Traps

### Interrupts

Interrupts are hardware events that send a signal to the CPU (or set flags.)

ex. timer expired, i/o waiting/complete, keyboard strokes

### Traps

Traps are software events that occur under a condition:

ex. exceptions, system calls.

## Why different modes?

- Maintains separation of privileges.
- Protects hardware.
- Simplifies programming experiencing by taking hardware interfacing out of the hands of programmers.

System calls are generic in nature for users (i.e. they look the same on all systems that share an OS), but are specific to machine/hardware.

# Code

### Exercise 0: ```time``` utility

- Run ```time -p``` on ```readStream.cpp``` with ```t4.txt``` as input.
- Use ```./dup.py X < t4.txt | time -p ./rs``` with various X values. 20MB and 200MB are good.
- Understand the difference between *real*, *user*, and *sys* time.

### Exercise 1: Compiled vs. Interpreted Languages

- Use ```strace -c``` on ```fibonacci.py``` and ```fibonacci.cpp```.
- Use ```strace -c``` on ```1-SetUp/dummy_files.cpp``` on 0, 100, and 200 inputs.
- Discuss Compiled vs. Interpreted with respect to System calls.

### Exercise 2: Improve efficiency of ```readStream.cpp```

- Make a small modification to ```readStream.cpp``` so that it runs much faster on large inputs.
- Discuss the size of pipes, and why you don't get endless efficiency increases by making larger buffers.

### Exercise 3: Open file

- Review ```fileOpen.cpp```
- Discuss File Descriptors, stdin, stdout, stderr.

### Exercise 4: Create file

- Review ```fileCreate.cpp```
- Discuss flags for opening files.

---

# Part 2: System Calls

*Q*: What are system calls?

*A*: System calls are how programs request services from the kernel.

## File IO

Files can be opened, read, and modified in several different ways.

We can use the system call ```read()```, the C library call ```fread()```, or C++ file streams ```std::ifstream``` and ```std::ofstream```.

Each of them accomplish effectively the same thing, they all open up some file name and enable us to read bytes of data into our program.

Review the three options detailed in ```fileIO.cpp```.

## Making System Calls

We can invoke system calls from a C program by using the ```system()``` method.

Review ```system_calls.cpp``` to see some options. They invoke familiar linux commands.

The use of ```system()``` can be limited because our program can't use the results of the calls. Instead, we have ```popen()``` as a means to stream the data from a system call into our program.

Review ```popen.cpp``` to see two examples. The ```count_file_types()``` method *may* be skipped, however it *may* be useful for the next assignment.

### Exercise 0: Decode a hidden message

- Complete an implementation for ```hidden.cpp```