// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

// TC - there are N places to fill with M choices for each, so wouldn't M be multiplied N times 
bool isValid(int node, int n, int col, bool graph[101][101], int* color){
    for(int i=0;i<n;i++){
        if((i!= node) && graph[node][i] == 1 && color[i] == col) return false;
    }
    
    return true;
}
bool solve(int node, bool graph[101][101], int m, int n, int* color){
    if(node == n)return true;
    
    for(int i=1;i<=m;i++){
        if(isValid(node, n, i, graph, color)){
            color[node]=i;
            if(solve(node+1, graph, m, n, color)) return true;
            color[node]=0;
        }
    }
    
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n]={0};
    if(solve(0, graph, m, n, color)) return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
