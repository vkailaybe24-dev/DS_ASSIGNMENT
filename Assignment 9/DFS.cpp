#include<iostream>
#include<vector>
using namespace std;
void dfsUtil(int u, vector<vector<int>>& adj, vector<bool>& visited){
    visited[u] = true;
    cout<<u<<" ";
    for(int v : adj[u]){
        if(!visited[v]) dfsUtil(v, adj, visited);
    }
}
void dfs(int start, vector<vector<int>>& adj, int V){
    vector<bool> visited(V, false);
    dfsUtil(start, adj, visited);
}
int main(){
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2}; 
    adj[1] = {0, 3, 4}; 
    adj[2] = {0}; 
    adj[3] = {1}; 
    adj[4] = {1};
    cout<<"DFS starting from node 0: ";
    dfs(0, adj, V);
    cout<<endl;
    return 0;
}
