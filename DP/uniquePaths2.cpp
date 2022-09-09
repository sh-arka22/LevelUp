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
vector<vector<int>>dp;
int recc(int n, int m, vector<vector<int>>&grid){
    if(n<0 or m<0) return 0;
    if(n==0 and m==0) return 1;

    int left = 0;int right = 0;
    if(m>0){
        right = grid[n][m-1] ? 0 : recc(n,m-1, grid);
    }
    if(n>0){
        left = grid[n-1][m] ? 0 : recc(n-1,m, grid);
    }
    return left + right;
}

int tabu(int N, int M, vector<vector<int>>&grid){
    for(int n =0;n<=N;n++){
        for(int m=0;m<=M;m++){
            if(n<0 or m<0){
                dp[n][m] = 0;
                continue;
            }
            if(n==0 and m==0){
                dp[n][m] = 1;
                continue;
            }

            int left = 0;int right = 0;
            if(m>0){
                right = grid[n][m-1] ? 0 : dp[n][m-1];
            }
            if(n>0){
                left = grid[n-1][m] ? 0 : dp[n-1][m];
            }
            dp[n][m] = left + right;
        }
    }
    return dp[N][M];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size()-1;
    int m = obstacleGrid[0].size()-1;
    dp.resize(n, vector<int>(m,0));
    if(obstacleGrid[0][0] or obstacleGrid[n][m]) return 0;
    return recc(n,m,obstacleGrid);
}

int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}