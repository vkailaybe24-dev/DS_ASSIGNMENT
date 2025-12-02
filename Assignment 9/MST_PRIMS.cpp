#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
void primMST(vector<vector<pii>>& adj, int V){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int src = 0;
    vector<int> key(V, 99999);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push({0, src});
    key[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(inMST[u]) continue;
        inMST[u] = true;
        for(auto x : adj[u]){
            int v = x.first;
            int weight = x.second;
            if(!inMST[v] && key[v] > weight){
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    cout<<"Edge \tWeight\n";
    for(int i = 1; i < V; ++i)
        cout<<parent[i]<<" - "<<i<<"\t"<<key[i]<<"\n";
}
int main(){
    int V = 5;
    vector<vector<pii>> adj(V);
    adj[0].push_back({1, 2}); adj[1].push_back({0, 2});
    adj[0].push_back({3, 6}); adj[3].push_back({0, 6});
    adj[1].push_back({2, 3}); adj[2].push_back({1, 3});
    adj[1].push_back({3, 8}); adj[3].push_back({1, 8});
    adj[1].push_back({4, 5}); adj[4].push_back({1, 5});
    adj[2].push_back({4, 7}); adj[4].push_back({2, 7});
    adj[3].push_back({4, 9}); adj[4].push_back({3, 9});
    primMST(adj, V);
    return 0;
}
