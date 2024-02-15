# INF224 Ronan Lebas
This repository contains the lab work from the 2023-2024 course INF224 of Télécom Paris.  
All mandatory questions have been answered.

## Code
* The C++ server is in `cpp`, the code is memory-leaks proof
* The Java client is in `swing`
* Each of these folders have a Makefile to compile and execute with `make run`

In `cpp/main.cpp`, there are three functions that can be called by the `main` function:
1. `test` for testing the management of objects and memory
2. `serial` for testing the serialization
3. `server` for testing the interaction with the Java client

By default the program will execute these three functions, but one can look for memory leaks using `valgrind` by commenting the call to `server` in `main` (because the server is an infinite loop, so `valgrind` cannot be used).

## Questions
Here are the answers to the questions of the lab:
* 

## Explanations
I chose to use exceptions for C++ step 13, but I think the way inputs are processed remove the need for a lot of exceptions: for instance, if the user wants to search an object which doesn't exist, the server will simply respond with a message indicating the object cannot be found, so using exceptions in such cases is not worth.