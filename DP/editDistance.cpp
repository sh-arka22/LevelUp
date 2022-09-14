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
int recc(string s1, string s2, int n, int m){
    if(n==0 or m==0){
        if(n>0) return dp[n][m] = n;
        if(m>0) return dp[n][m] = m;
        return dp[n][m] = 0;
    }
    
    if(dp[n][m] != -1) return dp[n][m];
    int deletion = (int)1e9, insertion = (int)1e9, replace = (int)1e9;
    
    if(s1[n-1] == s2[m-1]){
        replace = recc(s1, s2, n-1, m-1);
    }
    else{
        deletion = recc(s1, s2, n-1, m)+1;
        insertion = recc(s1, s2, n, m-1)+1;
        replace = recc(s1, s2, n-1, m-1)+1;
    }

    return dp[n][m] = min(insertion, min(deletion,replace));
}


int editDistance(string str1, string str2){
    //write you code here
    int n = str1.size(), m = str2.size();

    return recc(str1, str2, n, m);
}



int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}