#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
typedef pair<int, int> pii;
void dijkstra(vector<vector<pii>>& adj, int src, int V){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto x : adj[u]){
            int v = x.first;
            int weight = x.second;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout<<"Vertex \tDistance from Source\n";
    for(int i = 0; i < V; ++i)
        cout<<i<<"\t"<<dist[i]<<"\n";
}
int main(){
    int V = 5;
    vector<vector<pii>> adj(V);
    adj[0].push_back({1, 9}); 
    adj[0].push_back({2, 6}); 
    adj[0].push_back({3, 5}); 
    adj[0].push_back({4, 3});
    adj[2].push_back({1, 2}); 
    adj[2].push_back({3, 4});
    cout<<"Dijkstra Shortest Path from Node 0:\n";
    dijkstra(adj, 0, V);
    return 0;
}
