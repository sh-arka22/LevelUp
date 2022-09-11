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

vector<vector<int>>dp;
bool tabu(int N, int Tar, vector<int>&arr){
    for(int n=0; n<=N;n++){
        for(int tar=0;tar<=Tar;tar++){ // has to be started from the 0
            if(n==0 or tar ==arr[n]){
                dp[tar][n] = (tar==arr[n]);
                continue;
            }
            bool flag = false;
            if(tar - arr[n] >= 0){
                flag = flag or dp[tar-arr[n]][n-1];
            }
            flag = flag or dp[tar][n-1];

            dp[tar][n] = flag;
        }
    }
    return dp[Tar][N];
}

bool canPartition(vector<int>& nums, int n) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%2) return false;
    dp.resize((sum/2)+1,vector<int>(n,-1));
    int ans = tabu(n-1, sum/2, nums);
    dp.clear();
    return ans;   
}
//****************************************************************

int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}