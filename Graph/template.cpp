// Problem Link - 
/* By Arkajyoti Saha */
#include<bits/stdc++.h>
using namespace std;


void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
//######################################################################################################################################################################
// using DFS
void dfs(vector<int>graph[], int v, int vis[]){
    vis[v] = 1;
    for(auto child: graph[v]){
        if(!vis[child])
            dfs(graph, child, vis);
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int v = isConnected.size();
    vector<int>graph[v];
    for(int i=0;i<v;i++){
        for(int j=i+1;j<v;j++){
            if(isConnected[i][j]){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    int vis[v];
    fill(vis, vis+v, 0);
    int cnt = 0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(graph, i, vis);
            cnt++;
        }
    }
    return cnt;
}


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}