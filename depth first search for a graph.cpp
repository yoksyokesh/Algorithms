// ALGORITHM : Depth First Search for a Graph
// TIME COMPLEXITY : O(nodes+edges)

#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> adj[], bool *visited)
{
    visited[s] = true; // marking current node as visited, so that we will have a record on which nodes are visited in dfs
    cout << s << " ";
    for (int i = 0; i < adj[s].size(); ++i)
    {
        if (visited[adj[s][i]] == false)
        {
            dfs(adj[s][i], adj, visited); // recursively calling our dfs function
        }
    }
}

int main()
{
    int t;
    cin >> t; // to run through multiple test cases
    while (t--)
    {
        int nodes, edges; // nodes - number of nodes in graph, edges - number of edges in graph
        cin >> nodes >> edges;
        vector<int> adj[nodes]; // creating adjacency list
        bool visited[nodes];
        memset(visited, false, sizeof(visited)); // setting all nodes to false, since we haven't visited any node yet
        for (int i = 0; i < edges; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, adj, visited); // calling dfs function
        cout << '\n';
    }
    return 0;
}
