#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{ int src, dest, weight; };
bool compareEdges(Edge a, Edge b){ return a.weight < b.weight; }
struct DSU{
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j){
        int root_i = find(i);
        int root_j = find(j);
        if(root_i != root_j) parent[root_i] = root_j;
    }
};
int main(){
    int V = 4;
    vector<Edge> edges = {{0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}};
    sort(edges.begin(), edges.end(), compareEdges);
    DSU dsu(V);
    int mst_weight = 0;
    cout<<"Edges in MST:\n";
    for(Edge e : edges){
        if(dsu.find(e.src) != dsu.find(e.dest)){
            dsu.unite(e.src, e.dest);
            mst_weight += e.weight;
            cout<<e.src<<" -- "<<e.dest<<" == "<<e.weight<<endl;
        }
    }
    cout<<"Total MST Weight: "<<mst_weight<<endl;
    return 0;
}
