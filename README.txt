This README contains information about the libminCost.o and the libcycles.o Linux dynamic libraries.

libcycles.o:

This function validates that the absence of cycles in the graph given to the algorithm. If a cycle is found then the Traveling Salesman Algorithm cannot be performed.

int validateCyclicGraph(int n, int mat[n][n])

Where n is one of the dimensions of the graph and mat is the graph itself.

libminCost.o:

This function computes the shortest path between two points using the Traveling Salesman Algorithm and displays the amount of nodes in the shortes path.

void printMinCost(int n, int m[n][n])

Whwhere n is one of the dimensions of the graph and m is the graph itself.


