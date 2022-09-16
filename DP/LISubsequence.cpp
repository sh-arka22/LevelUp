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
int solve(vector<int>& nums, int i, int prev) {
    if(i < 0) return 0;                                // cant pick any more elements
    
    int pick = (nums[i] < prev) ? solve(nums, i - 1, nums[i])+1 : 0;
    int dontPick = solve(nums, i-1, prev);
    
    return max(pick, dontPick);
}
//******************* USING COMBINATION METHOD *************************************************************************************************************
/*
    space optimised
*/
int recc(vector<int>& nums, int idx){
    if(idx < 0) return 0;
    int cnt = 1;
    for(int i=idx-1;i>=0;i--){
        if(nums[idx]>nums[i]){
            int faith = recc(nums, i) ;
            cnt = max(cnt, faith+1);
        }
    }
    return cnt;
}

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = -1;
        for(int i=1;i<=n;i++){
            maxLen = max(maxLen,recc(nums, i));
        }
        return maxLen;
    }
//****************************************************************************************************************************************************************
/**
 * time optimised 
 */
vector<vector<int>>dp;
    int solve(vector<int>& nums, int i, int prevIdx) {
    if(i < 0) return 0;                                // cant pick any more elements
    if(dp[i][prevIdx] != -1) return dp[i][prevIdx];
    int pick = (prevIdx == nums.size() or nums[i] < nums[prevIdx]) ? solve(nums, i - 1, i)+1 : 0;
    int dontPick = solve(nums, i-1, prevIdx);
    
    return dp[i][prevIdx] = max(pick, dontPick);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    dp.resize(n, vector<int>(n+1, -1));
    return solve(nums, n-1,n);
}
//******************************************************************************************************
// ------------- TABULISATION --------------------------------
vector<int>dp;
int recc(vector<int>& nums, int Idx){
    for(int idx=0;idx<=Idx;idx++){
        if(idx-1 < 0){
            dp[idx] = 0;
            continue;
        }
        int cnt = 1;
        for(int i=idx;i>=1;i--){
            if(nums[idx-1]>nums[i-1]){
                int faith = dp[i];
                cnt = max(cnt, faith+1);
            }
        }
        dp[idx] = cnt;
    }
    return 1;
}
vector<int> print(vector<int>& nums, int Idx){
    vector<int>ans(nums.size());
    for(int idx=0;idx<=Idx;idx++){
        if(idx-1 < 0){
            dp[idx] = 0;
            continue;
        }
        ans[idx] = idx;
        int cnt = 1;
        for(int i=idx;i>=1;i--){
            if(nums[idx-1]>nums[i-1]){
                int faith = dp[i]+1;
                if(faith > cnt){
                    ans[idx] = i;
                }
                cnt = max(cnt, faith);
            }
        }
        dp[idx] = cnt;
    }
    return ans;
}
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = -1;
        int maxIdx = -1;
        dp.resize(n+1, -1);
        int call = recc(nums, n);
        for(int i=1;i<n+1;i++){
            if(maxLen > dp[i]) maxIdx = i;
            maxLen = max(maxLen,dp[i]);
        }
        vector<int> ans = print(nums, maxIdx);
        return maxLen;
    }
//************************************************************************************************************************************
int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}