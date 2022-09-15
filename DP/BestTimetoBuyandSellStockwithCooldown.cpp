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
int recc(vector<int>& prices, int idx, int n, int state) {
    if(idx >= n) return dp[idx][state] = 0;
    if(dp[idx][state] != -1) return dp[idx][state];
    int profit;
    if(state == 0){
        //i can buy;
        profit = max(recc(prices, idx+1, n, 0), recc(prices, idx+1, n, 1) - prices[idx]);
    }
    else{
        //i can sell;
        profit = max(recc(prices, idx+1, n, 1), prices[idx] + recc(prices, idx+2, n, 0));
    }
    return dp[idx][state] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    dp.resize(n+2, vector<int>(2,-1));
    return recc(prices, 0, n, 0); 
}

int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}