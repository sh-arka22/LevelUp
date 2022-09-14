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

int recc(string &s, int st, int en, vector<vector<int>>&dp){
    for()
    if(st>=en) return dp[st][en] = (st == en ? 1 : 0);
    if(dp[st][en] != -1) return dp[st][en];
    int cnt;
    if(s[st] != s[en]){
        cnt = max(recc(s,st+1,en,dp),recc(s,st,en-1,dp));
    }
    else cnt = (recc(s,st+1,en-1,dp)+2);

    return dp[st][en] = cnt;
}


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}