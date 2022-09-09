
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
int recc(int n, int m){
    if(n==0 or m==0) return dp[n][m] = 1;
    if(dp[n][m] != -1) return dp[n][m];
    int left = recc(n-1,m);
    int right = recc(n,m-1);

    return dp[n][m] = (left + right);
}

int uniquePaths(int m, int n) {
    dp.resize(m, vector<int>(n,-1));
    return recc(m-1,n-1);
}



int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}