
/* ------- Necessary functions for the interface functions  ------ */
int numElementos(unsigned int b) {
    int cont = 0;
    while(b) {
        if (b & 1) cont++;
        b = b >> 1;
    }
    return cont;
}
int isBitOn(unsigned int bitmask, int pos) {
    return (bitmask & (1 << pos));
}
int turnOffBit(unsigned int bitmask, int pos) {
    return (bitmask & ~(1 << pos));
}



/* ------ Interface functions ----- */

// printMinCost
// n -- Number of nodes (cities)
// m[][] -- adjacency matrix, -1 when there is not a connection and a positive number to specify the cost of the edge

void printMinCost(int n, int m[n][n]) {
    //generate subsets
    int subset[30][30];
    int subset_index[30];
    memset(subset_index, 0, sizeof(subset_index));
    for(unsigned int bitmask=1; bitmask <= (1 << n); bitmask++) {
        int m = numElementos(bitmask);
        subset[m][subset_index[m]++] = bitmask;
    }
    
    //TSP algorithm
    int dp[30][30];
    for(int i=1;i<n;i++)
        dp[i][0] = m[i][0];
    
    for(int k=1;k<=n-1;k++) { //I'll try with subsets of size k
        for(int j=0;j<subset_index[k];j++) {//travel through all subsets of size k
            //for each subset[k][j] I'll do the following
            for(int i=1;i<n;i++) { //iterate over the nodes (cities)
                if (isBitOn(subset[k][j],i) == 0 && isBitOn(subset[k][j], 0) == 0) { //if neither Vi and V0 are in the subset, I check it.
                    int current_min = 9999; //here D[i,A] = min(W[i,j] + D[j, A - {vj}])
                    for(int l=1;l<n;l++) { //Cheking all l's of the subset.
                        if(isBitOn(subset[k][j],l) && m[i][l] != -1) { //si l esta en el subconjunto y hay camino de vi a l
                            int aux = m[i][l] + dp[l][turnOffBit(subset[k][j], l)];
                            if(aux < current_min)
                                current_min = aux;
                        }
                    }
                    dp[i][subset[k][j]] = current_min;
                }
            }
        }
    }
    
    
    int current_min = 9999;
    int pi = 0;
    for(int l=1; l < n; l++) {
        if(m[0][l] != -1 ) {
            int aux = m[0][l] + dp[l][turnOffBit((1 << n)-2, l)];
            if(aux < current_min) {
                current_min = aux;
                pi = l;
            }
        }
    }
    
    dp[0][(1<<n)-1] = current_min + pi;
    printf("minimum hamiltonian path: %d\n", dp[0][(1<<n)-1]);
    
}

// validateAcyclicGraph: useful to know if we can apply TSP algorithm
int validateAcyclicGraph(int n, int mat[n][n]) {
    return 1;
}

