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
int recc(vector<vector<int>>& triangle, int n, int r, int c){
    if(r == n) return dp[r][c] = triangle[r][c];
    if(dp[r][c] != -1) return dp[r][c];
    int d = (int)1e9;
    int dg = (int)1e9;
    if(r<n){
        d = recc(triangle, n, r+1, c);
    }
    if(r<n and c<n){
        dg = recc(triangle, n, r+1, c+1);
    }
    return dp[r][c] = min(d, dg)+triangle[r][c];
}
//****************************************************************
vector<vector<int>>dp;
int tabu(vector<vector<int>>& triangle, int n, int R, int C){
    for(int r=n;r>=0;r--){
        for(int c=n;c>=0;c--){
            if(r==n){
                dp[r][c] = triangle[r][c];
                continue;
            }
            int d = (int)1e9;
            int dg = (int)1e9;
            if(r<n){
                d = dp[r+1][c];
            }
            if(r<n and c<n){
                dg = dp[r+1][c+1];
            }
            dp[r][c] = min(d,dg) + triangle[r][c];
        }
    }
    return dp[R][C];
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size()-1;
    dp.resize(n+1, vector<int>(n+1,-1));
    return recc(triangle, n, 0, 0);
}


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}