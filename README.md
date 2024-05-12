# Graph Algorithms Library

This is a C++ library for performing various graph algorithms. It includes implementations for algorithms such as checking if a graph is connected, finding the shortest path between two vertices, detecting cycles in a graph, determining if a graph is bipartite, and finding negative cycles in a weighted graph.

## Overview

The library consists of several files:

- `Algorithms.cpp` and `Algorithms.hpp`: Implementations of various graph algorithms.
- `Graph.cpp` and `Graph.hpp`: Implementation of the Graph class used to represent a graph.
- `Demo.cpp`: A demonstration of how to use the library to perform graph operations.
- `testCounter.cpp`: A test runner to ensure a minimum number of tests are written.

## Files

### Algorithms.cpp and Algorithms.hpp

These files contain the implementation of various graph algorithms, including:

- `isConnected`: Checks if the graph is connected.
- `shortestPath`: Finds the shortest path between two vertices in the graph.
- `isContainsCycle`: Checks if the graph contains a cycle.
- `isBipartite`: Checks if the graph is bipartite.
- `negativeCycle`: Finds a negative cycle in the graph.

### Graph.cpp and Graph.hpp

These files contain the implementation of the `Graph` class, which represents a graph using an adjacency matrix.

- `loadGraph`: Loads a graph from a given adjacency matrix.
- `printGraph`: Prints information about the graph, including the number of vertices and edges.
- `getMatrix`: Returns the adjacency matrix of the graph.

### Demo.cpp

This file demonstrates how to use the graph algorithms library to perform various operations on graphs.

### testCounter.cpp

This file contains a test runner to ensure that a minimum number of tests are written for the library.

## Usage

To use the library, include the necessary header files (`Algorithms.hpp` and `Graph.hpp`) in your C++ project and link against the implementation files (`Algorithms.cpp` and `Graph.cpp`).

```cpp
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>

int main() {
    // Create a graph
    ariel::Graph g;

    // Load graph data
    std::vector<std::vector<int>> graphData = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graphData);

    // Use graph algorithms
    std::cout << "Is connected: " << ariel::Algorithms::isConnected(g) << std::endl;
    // Perform other operations...

    return 0;
}


# Explanation of Makefile Content

## Variables
- `CXX`: Specifies the C++ compiler as `clang++`.
- `CXXFLAGS`: Compiler flags for C++ code, including `-std=c++11`, `-Werror` (treats warnings as errors), and `-Wsign-conversion` (warns about implicit conversions that may change the sign of a value).
- `VALGRIND_FLAGS`: Flags for running `valgrind` memory analysis.

## Source Files
- `SOURCES`: List of source files including `Graph.cpp`, `Algorithms.cpp`, `TestCounter.cpp`, and `Test.cpp`.
- `OBJECTS`: List of object files derived from source files by replacing `.cpp` with `.o`.

## Targets
- `run`: Executes both `demo` and `test`.
- `demo`: Compiles and links `Demo.o` and other object files (excluding `TestCounter.o` and `Test.o`) into an executable named `demo`.
- `test`: Compiles and links `TestCounter.o` and `Test.o` and other object files (excluding `Demo.o`) into an executable named `test`.
- `tidy`: Runs `clang-tidy` on source files with specific checks, treating warnings as errors.
- `valgrind`: Runs `valgrind` on both `demo` and `test` executables, checking for memory leaks.

## Pattern Rule
- `%.o: %.cpp`: Compiles each `.cpp` file into an object file.

## Clean Target
- `clean`: Removes object files (`*.o`), `demo`, and `test` executables.
