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
int recc(vector<int> wt, vector<int> val, int n, int w){
    if(n==0){
        if(wt[0]<=w) return dp[n][w] = val[0];
        else return 0;
    }
    if(dp[n][w] != -1) return dp[n][w];
    int pick = 0;
    if(wt[n] <= w){
        pick = val[n] + recc(wt, val, n-1, w-wt[n]);
    }
    int notPick = recc(wt, val, n-1, w);

    return dp[n][w] = max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    // Write your code here
    dp.resize(n, vector<int>(maxWeight+1, -1));
    int ans = recc(weight, value, n-1, maxWeight);
    dp.clear();
    return ans;
}


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}