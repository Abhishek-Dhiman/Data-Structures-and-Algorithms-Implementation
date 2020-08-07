#include<bits/stdc++.h>
using namespace std;
bool visited[100000];
vector <int> adj[100000];
int main()
{
    int nodes; // vertices
    cin >> nodes;
    int edges; // edges
    cin >> edges;

    for (int i = 1; i <= nodes; i++) // Initially, assuming all vertices are not visited...
        visited[i] = false;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // assuming undirected edges i.e. if u is connected to v, and v is connected to u
        adj[v].push_back(u);
    }

    int startnode; // starting vertex from where dfs will start
    cin >> startnode;
    stack <int> s;
    s.push(startnode);

    cout << "The DFS traversal of a graph is :" << "\n";

    while (!s.empty()) // terminating condition until all vertices are visited
    {
        int popped = s.top();
        cout << popped << " ";
        visited[popped] = true; // means vertex is visited
        s.pop();
        for (auto j : adj[popped]) // In this loop we will add all adjacent vertex to stack
        {
            if (!visited[j])
            {
                s.push(j);
            }
        }
    }

    return 0;
}
