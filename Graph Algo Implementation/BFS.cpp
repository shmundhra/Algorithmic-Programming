#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m;
    cin>>n>>m;

    vector<int> adj[n];      // int -> pair < int, int > in case of Weights
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        x--, y--;                  // Depends on Indexing
        adj[x].push_back(y);
        adj[y].push_back(x);       // Depends on Directed Undirected
    }

    vector<int> visited  (n,  0);
    vector<int> parent   (n, -1);
    vector<int> distance (n, -1);
    vector<int> component(n, -1);
    int connected_components = 0;

    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == 1) continue;
        
        connected_components++;
        queue <int> DS;

        int source = i;
        visited[source] = 1;
        parent[source] = -1;
        distance[source] = 0;
        component[source] = connected_components;
        
        DS.push(source);
        while (!DS.empty())
        {
            int current = DS.front();
            DS.pop();

            for (int j = 0; j < (int)adj[current].size(); j++)
            {
                int child = adj[current][j];
                if (visited[child] == 0)
                {
                    visited[child]   = 1;
                    parent[child]    = current;
                    distance[child]  = distance[current] + 1;
                    component[child] = connected_components;
                    DS.push(child);
                }
            }
        }
    }
    
}
