#include <iostream>
#include <bits/stdc++.h>
#include <utility>
#define MAX 100
using namespace std;
typedef pair<int, int> p;
bool marked[MAX];
vector <p> edges[MAX];



int prim(int x){
    priority_queue< p, vector<p>, greater<p> > Q;
    p temp;
    int cost = 0;
    Q.push(make_pair(0, x));
    while(!Q.empty()){
        temp = Q.top();
        Q.pop();
        x = temp.second;
        // Checking If Already Present:
        if(marked[x] == true)
            continue;
        cost += temp.first;
        marked[x] = true;
        // Add the nodes connected to the recently added node in the queue:
        for(int i=0; i<edges[x].size(); i++){
            int y = edges[x][i].second;
            if(marked[y] == false){
                Q.push(edges[x][i]);
            }
        }
    }
    return cost;
}

// Inputs:
int main(){
    int v_num, e_num, from, to;
    cout<<"Enter the number of nodes and edges: "<<endl;
    cin>>v_num>>e_num;
    int weight, x, y;
    for(int i=0; i<e_num; i++){
        cout<<"Enter Weights, Node1, Node2 of "<<i<<" row"<<endl;
        cin>>weight>>x>>y;
        edges[x].push_back(make_pair(weight, y));
        edges[y].push_back(make_pair(weight, x));
    }
    int minCost = 0;
    minCost = prim(1);
    cout<<"Minimal Cost Will be: "<<minCost<<endl;
    return 0;
}

// Complexity Of Prims Algorithm is:
// 1. Time to insert in priority queue i.e. logV
// Complexity: O((V + E) * logV)
