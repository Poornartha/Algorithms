
// Dijkstra's Algorithm ->

#include <iostream>
#include <bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;
typedef pair< int, int > p;

void addEdge( vector <p> adj[], int u, int v, int wt){
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath( vector <p> adj[], int V, int src ){
    priority_queue< p, vector<p>, greater<p> > pq;

    vector <int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        vector< pair<int, int> >::iterator k;
        for(k = adj[u].begin(); k != adj[u].end(); ++k){
            int v = (*k).first;
            int w = (*k).second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source: \n");
    for(int i=0; i<V; ++i){
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}

int main(){
    int V = 9;
    vector< p > adj[V];

    // making a sample graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    shortestPath(adj, V, 0);

    return 0;
}
