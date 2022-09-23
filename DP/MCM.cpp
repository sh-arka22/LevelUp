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
int memoisation(vector<int>&arr, int si, int ei){
    if(ei-si == 1) return 0;
    if(dp[si][ei] !+ 0) return dp[si][ei];
    int mini = (int)1e9;
    for(int cut = si+1; cut<ei; cut++){
        int left = memoisation(arr, si, cut);
        int right = memoisation(arr, cut, ei);
        mini = min(mini, left + right + arr[si]*arr[cut]*arr[ei]);
    }
    return dp[si][ei] = mini;
}
//*********************************** TABULISATION  ******************************************
int TABULISATION(vector<int>&arr, int SI, int EI){
    for(int gap = 1; gap<n; gap++){
        for(int si = 0, ei = gap; ei<n; si++, ei++){
            if(ei-si == 1){
                dp[si][ei] = 0;
                continue;
            }
            int mini = (int)1e9;
            for(int cut = si+1; cut<ei; cut++){
                int left = dp[si][cut];
                int right = dp[cut][ei];
                mini = min(mini, left + right + arr[si]*arr[cut]*arr[ei]);
            }
            dp[si][ei] = mini;
        }
    }
    return dp[SI][EI];
}




int matrixMultiplication(vector<int> &arr, int N){
    // Write your code here.
    int si = 0, ei = arr.size()-1;
    dp.resize(ei+1, 0);
    return memoisation(arr, 0, ei);
}


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}