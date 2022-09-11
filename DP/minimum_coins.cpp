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
int recc(vector<int> &num, int tar, int n){
    if(n==0){
        if(tar % num[0] == 0) return dp[n][tar] = tar/num[0];
        return dp[n][tar] = (int)1e9;
    }
    if(dp[n][tar] != -1) return dp[n][tar];
    int pick = (int)1e9;
    if(tar>=num[n]){
        pick = recc(num, tar-num[n], n)+1;
    }
    int notPick = recc(num, tar, n-1);

    return dp[n][tar] = min(pick, notPick);
}

int minimumElements(vector<int> &num, int x){
    // Write your code here.
    int n = num.size();
    dp.resize(n, vector<int>(x+1, -1));
    int ans = recc(num, x, n-1) == (int)1e9 ? -1 : recc(num, x, n-1);
    dp.clear();
    return ans;
}
//******************** TABULISATION   ********************************************
vector<vector<int>>dp;
int recc(vector<int> &num, int Tar, int N){
    for(int n=0;n<=N;n++){
        for(int tar=0;tar<=Tar;tar++){
            if(n==0){
                if(tar % num[0] == 0){
                    dp[n][tar] = tar/num[0];
                    continue;
                }
                dp[n][tar] = (int)1e9;
                continue;
            }
            int pick = (int)1e9;
            if(tar>=num[n]){
                pick = dp[n][tar-num[n]]+1;
            }
            int notPick = dp[n-1][tar];
            dp[n][tar] = min(pick, notPick);
        }
    }
    return dp[N][Tar];
}

int minimumElements(vector<int> &num, int x){
    // Write your code here.
    int n = num.size();
    dp.resize(n, vector<int>(x+1, -1));
    int ans = recc(num, x, n-1) == (int)1e9 ? -1 : recc(num, x, n-1);
    dp.clear();
    return ans;
}


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}