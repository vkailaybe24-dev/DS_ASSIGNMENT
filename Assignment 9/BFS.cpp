#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int start, vector<vector<int>>& adj, int V){
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
int main(){
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2}; 
    adj[1] = {0, 3, 4}; 
    adj[2] = {0}; 
    adj[3] = {1}; 
    adj[4] = {1};
    cout<<"BFS starting from node 0: ";
    bfs(0, adj, V);
    cout<<endl;
    return 0;
}
