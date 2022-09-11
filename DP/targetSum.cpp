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
bool recc(int n, int tar, vector<int>arr){
    if(n==0 or tar ==0) return (tar==0);

    bool flag = false;
    if(tar - arr[n] >= 0){
        flag = recc(n-1, tar-arr[n], arr);
    }
    flag = flag or recc(n-1, tar, arr);

    return flag;
}
//********************************************************************************************************
vector<vector<int>>dp;
bool recc(int n, int tar, vector<int>arr){
    if(n==0 or tar ==arr[n]) return dp[tar][n] = (tar==arr[n]);
    if(dp[tar][n] != -1) return dp[tar][n];
    bool flag = false;
    if(tar - arr[n] >= 0){
        flag = flag or recc(n-1, tar-arr[n], arr);
    }
    flag = flag or recc(n-1, tar, arr);

    return dp[tar][n] = flag;
}
//****************************************************************

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return recc(n-1, k, arr);
}


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}