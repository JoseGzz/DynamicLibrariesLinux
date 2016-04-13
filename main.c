#include<stdio.h>
#include<string.h>


int main() {
    int mat[5][5] = {
        {-1,  2, -1, -1,  4},
        { 2, -1, -1, -1,  1},
        { 1, -1, -1,  1,  2},
        {-1,  2,  6, -1, -1},
        {-1,  2,  4,  1, -1}
    };
    
    if(validateCyclicGraph(5, mat) > 0)
        printMinCost(5, mat);
}
