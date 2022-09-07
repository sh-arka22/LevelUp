// Problem Link - https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-without-adjacents
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

int *dp;
int recc(int arr[], int n){
    if(n == 0) return dp[n] = arr[0];
    if(n == 1) return dp[n] = max(arr[0],arr[1]);
    if(dp[n] != -1) return dp[n];
    int pick = recc(arr, n-2) + arr[n];
    int npick = recc(arr, n-1);

    return dp[n] = max(pick,npick);
}

int findMaxSum(int *arr, int n) {
	    // code here
        dp = new int[n];
        fill(dp,dp+n,-1);
        return recc(arr, n-1);
}
//*************************************************************************
int tabu(int arr[], int N){
	for(int n = 0; n <= N; n++){
		if(n == 0){
			dp[n] = arr[0];
			continue;
		}
		if(n == 1){
			dp[n] = max(arr[0],arr[1]);
			continue;
		}
		int pick = dp[n-2] + arr[n];
		int npick = dp[n-1];
		dp[n] = max(pick,npick);
	}
    return dp[N];
}
//************************************************************************************************
//space optimisation
int tabu(int arr[], int N){
	int prev1 ,prev2 ,curr; 
	 prev1 = prev2 = curr = arr[0];
	for(int n = 0; n <= N; n++){
		if(n == 0){
			prev1 = arr[0];
			continue;
		}
		if(n == 1){
			prev2 = max(arr[0],arr[1]);
			continue;
		}
		int pick = prev1 + arr[n];
		int npick = prev2;
		curr = max(pick,npick);
		prev1 = prev2;
		prev2 = curr;
	}
    return prev2;
}


//*************************************************************************************************************
int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}