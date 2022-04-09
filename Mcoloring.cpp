// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool issafe(int node, int c, bool graph[101][101], int colord[], int V){
    int i;
    for(i=0;i<V;i++){
        if(i!=node && graph[i][node]==1 && colord[i]==c) return false;
    }
    return true;
}
bool mcolor(bool graph[101][101], int node, int m, int V, int colord[]){
    if(node==V) return true;
    int c;
    for(c=1;c<=m;c++){
        if(issafe(node, c, graph, colord, V)){
            colord[node]=c;
            if(mcolor(graph, node+1, m, V, colord)) return true;
            else colord[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int colord[V] = {0};
    if(mcolor(graph, 0, m, V, colord)) return true;
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