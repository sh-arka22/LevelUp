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

int recc(int n, vector<int> &heights){
    // Write your code here.
    if(n == 0) return 0;

    int left = recc(n-1, heights) + abs(heights[n] - heights[n-1]);
    int right = n-2 >= 0 ? recc(n-2, heights) + abs(heights[n-2] - heights[n]) : INT_MAX;
    return min(left, right);
}

//********************************************************************************************************************************
int *dp;
int recc(int N, vector<int> &heights){
    // Write your code here.
    for(int n=0;n<=N;n++){
        if(n == 0){
            dp[n] = 0;
            continue;
        }
//         if(dp[n] != -1) return dp[n];
        int left = dp[n-1] + abs(heights[n] - heights[n-1]);
        int right = n-2 >= 0 ? dp[n-2] + abs(heights[n-2] - heights[n]) : INT_MAX;
        dp[n] = min(right, left);
    }
    return dp[N];
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    dp = new int[n];
    fill(dp,dp+n, -1);
    return recc(n-1, heights);
}


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}