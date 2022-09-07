// Problem Link - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/permutation-i-official/ojquestion
//orddering dont matter here
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

int dir[4][2] = {{-1,0}, {1,0},{0,1},{0,-1}};
    int shortestPath(vector<vector<int>> &grid, int k) {
        int n = grid.size(), m = grid[0].size();
        
        queue<vector<int>>que;
        que.push({0,0,0,k});
        
        while(que.size()){
            auto top = que.front();
            que.pop();
            
            if(grid[top[0]][top[1]] == -1)
                continue;
            grid[top[0]][top[1]] = -1;
            // cout<<grid[top[0]][top[1]]<<endl;
            
            if(top[0] == n-1 and top[1] == m-1)
                return top[2];
            
            if(grid[top[0]][top[1]] == 1 and top[3]<0)
                continue;
            if(grid[top[0]][top[1]] == 1 and top[3]>0){
                top[3]--;
            }
            for(auto &[dr,dc]:dir){
                if(top[0]+dr < 0 or top[0]+dr == n or top[0]+dc < 0 or top[1]+dc == m)
                    continue;
                que.push({top[0]+dr,top[1]+dc,top[2]+1,top[3]});
            }
        }
        return -1;
    }

int main(){
    file_i_o();
    vector<vector<int>> grid = {{0,1,1},{1,1,1},{1,0,0}};
    int n = grid.size(), m = grid[0].size();

    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    
    cout<<shortestPath(grid,1)<<endl;
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
}