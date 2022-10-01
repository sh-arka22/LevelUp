class Solution {
  public:
    // Function to detect cycle in an undirected graph.
bool found(int V, vector<int> adj[], int n){
    vector<int>vis(n,0);
    deque<int> que;

    que.push_back(V);
    

    while(que.size()){
        int sz = que.size();
        while(sz--){
            int parr = que.front();
            que.pop_front();
            if(vis[parr] == 1) return true;

            vis[parr] = 1;
            for(int child:adj[parr]){
                if(child == parr) return true;  // NOTE   0-0 an edge from the node to the same node
                if(vis[child] == 1) continue;
                que.push_back(child);
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    bool flag = false;
    for(int v = 0;v<V;v++){
        flag = flag or found(v, adj, V);
    }
    return flag;
}