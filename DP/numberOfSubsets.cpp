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

// 16 13 16 6 tar->16
#include <bits/stdc++.h>

using namespace std;

int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(ind == 0){
        if(target == 0 and arr[0] == 0) return 2; // arr->{0}={},{0}
        if(target == 0 or target == arr[0]) return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}

int main() {
    file_i_o();
  vector<int> arr = {9,7,0,3,9,8,6,5,7,6};
  int k=31;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}
