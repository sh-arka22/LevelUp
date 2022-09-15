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
//Method 1
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    
    int mini = (int)1e9;
    int profit = 0;
    for(int i=0;i<n;i++){
        profit = max(profit, prices[i]-mini);
        mini = min(mini, prices[i]);
    }
    return profit;
}

//Method 2
vector<vector<int>>dp;
int recc(vector<int>& prices, int idx, int n, int state) {
    if(idx == n) return dp[idx][state] = 0;
    if(dp[idx][state] != -1) return dp[idx][state];
    int profit;
    if(state == 0){
        //i can buy;
        profit = max(recc(prices, idx+1, n, 0), recc(prices, idx+1, n, 1) - prices[idx]);
    }
    else{
        //i can sell;
        profit = max(recc(prices, idx+1, n, 1), prices[idx] + recc(prices, idx, n, 0));
    }
    return dp[idx][state] = profit;
}




int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}


