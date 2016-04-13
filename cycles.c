int validateGraph(int u, int p, int n, int m[n][n], int s[n]) {
    if(s[u] == 2)
        return -1;
    if(s[u] == 1)
        return 1;
    s[u] = 1;
    for(int i=0;i<n;i++) {
        if(m[u][i] != -1 && i != p) {
            return validateGraph(i, u, n, m, s);
        }
    }
    s[u] = 2;
    return -1;
}

int validateCyclicGraph(int n, int mat[n][n]) {
    int status[20];
    memset(status, 0, sizeof(status));
    return validateGraph(0, -1, n, mat, status);
}

