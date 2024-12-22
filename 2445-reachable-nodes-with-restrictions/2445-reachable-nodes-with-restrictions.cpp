/*
intution -
we can mark restricted nodes as visited , then we can start dfs with 0 as source, and whenever we reach a new node while performing dfs, we increment out count by 1. after performing dfs, this count will give us maximum number of nodes we can reach from node 0 without visiting a restricted node.
In this dfs, we would automatically not visit the restricted nodes, as they would have been already marked visited before performing dfs
*/
class Solution
{
public:
    void dfs(int u, vector<int> adj[], int &cnt, vector<bool> &vis)
    {
        vis[u] = true;
        cnt++; 
        for (auto v : adj[u])
        {
            if (vis[v] == false)
            {
                dfs(v, adj, cnt, vis);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<bool> visited(n, false);
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for (auto a : restricted)
        {
            visited[a] = true;
        }
        int count = 0;
        dfs(0, adj, count, visited);
        return count;
    }
};