// Kruskal's Algorithm:

// Finding Minimal Spanning Tree

#include <iostream>
#include <bits/stdc++.h>
#include <utility>
#define MAX 100
using namespace std;

int path[MAX], vertex, num_edges;
// Structure of a Node:
// < weight, <from-node, to-node> > node[]
pair <int, pair <int, int> > edge[MAX];

void init(){
    for(int i=0; i<MAX; i++){
        path[i] = i;
    }
}
// Root will help us identify from where a path has started.
// If the value returned by the root of one node is same as other than both the nodes complete a cycle.

int root(int x){
    while(path[x] != x){
        path[x] = path[path[x]];
        x = path[x];
    }
    return x;
}

void unite(int from, int to){
    int to_root = root(from);
    int from_root = root(to);
    path[to_root] = path[from_root];
}

int kruskal(pair <int, pair <int, int> > edge[]){
    int cost = 0;
    int weight, from, to;
    for(int i=0; i<num_edges; i++){
        from = edge[i].second.first;
        to = edge[i].second.second;
        weight = edge[i].first;
        // Check if the selected edges completes a cycle/not:
        if(root(from) != root(to)){
            cost += weight;
            unite(from, to);
        }
    }
    return cost;
}

int main(){
    int x, y, weight;
    cout<<"Enter the number of vertices and edges: "<<endl;
    cin>>vertex>>num_edges;
    init();
    for(int i=0; i<num_edges; i++){
        cout<<"Enter Weight and From and To nodes of "<<i<<" Edge:"<<endl;
        cin>>weight>>x>>y;
        edge[i].first = weight;
        edge[i].second.first = x;
        edge[i].second.second = y;
    }
    // Sort in ascending order:
    sort(edge, edge + num_edges);
    int minCost;
    minCost = kruskal(edge);
    cout<<"Minimum Cost of the thus created tree will be: "<<minCost<<endl;
    return 0;
}

// Complexity Of the Algorithm: O(E * logV)
