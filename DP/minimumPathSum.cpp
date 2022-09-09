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
int recc(vector<vector<int>>&grid, int n, int m){
    if(n == 0 and m == 0) return dp[n][m] = grid[n][m];
    if(dp[n][m] != -1) return dp[n][m];
    int leftmin = (int)1e9;
    int rightmin = (int)1e9;

    if(n>0){
        leftmin = recc(grid, n-1, m);
    }
    if(m>0){
        rightmin = recc(grid, n, m-1);
    }

    return dp[n][m] = min(leftmin, rightmin) + grid[n][m];
}

int minimumCostPath(vector<vector<int>>& grid) {
    int n = grid.size()-1;
    int m = grid[0].size()-1;
    dp.resize(n+1, vector<int>(m+1,-1));
    return recc(grid, n, m);
}

int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}