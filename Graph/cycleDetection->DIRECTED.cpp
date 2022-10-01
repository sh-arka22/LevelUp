//------------------ DFS SOLUTION ------------------
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int vis[], int pathVis[], vector<int> adj[], int v)
    {
        vis[v] = 1;
        pathVis[v] = 1;

        for (int child : adj[v])
        {
            if (!vis[child] and dfs(vis, pathVis, adj, child))
                return true;
            else if (pathVis[child])
                return true;
        }
        pathVis[v] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i] and dfs(vis, pathVis, adj, i) == true)
                return true;
        }
        return false;
    }
};

//***********************  BFS METHOD  ***************************
// KHANS ALGORITHM ****************
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        deque<int> que;
        int ind[V];
        fill(ind, ind + V, 0);

        for (int v = 0; v < V; v++)
            for (auto it : adj[v])
                ind[it]++;

        for (int v = 0; v < V; v++)
        {
            if (ind[v] == 0)
                que.push_back(v);
        }

        int cnt = 0;

        while (que.size())
        {
            int sz = que.size();
            while (sz--)
            {
                int v = que.front;
                que.pop_front();
                cnt++;
                for (auto it : adj[v])
                {
                    if (--ind[it] == 0)
                        que.push_back(it);
                }
            }
        }

        return cnt != V;
    }
};