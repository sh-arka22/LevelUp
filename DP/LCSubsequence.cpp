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

int recc(string s, int n, string t, int m){
    if(n<0 or m<0) return 0;

    int len = 0;
    if(s[n] == t[m]){
        len = recc(s, n-1, t, m-1) + 1;
    }
    else len = max(recc(s, n-1, t, m), recc(s, n, t, m-1));

    return len;
}

int lcs(string s, string t){
    int n = s.size(), m = t.size();
    //Write your code here
    return recc(s, n-1, t, m-1);
}
//**************************CHAINGING OF IDX TO CONTAIN IN DP **************************************

int recc(string s, int n, string t, int m){
    if(n==0 or m==0) return 0;

    int len = 0;
    if(s[n-1] == t[m-1]){
        len = recc(s, n-1, t, m-1) + 1;
    }
    else len = max(recc(s, n-1, t, m), recc(s, n, t, m-1));

    return len;
}

int lcs(string s, string t){
    int n = s.size(), m = t.size();
    //Write your code here
    return recc(s, n, t, m);
}

//*****************  TABULISATION     ******************************
vector<vector<int>>dp;
int recc(string s, int N, string t, int M){
    for(int n=0;n<=N; n++){
        for(int m=0; m<=M; m++){
            if(n==0 or m==0){
                dp[n][m] = 0;
                continue;
            }
            int len = 0;
            if(s[n-1] == t[m-1]){
                len = dp[n-1][m-1]+ 1;
            }
            else len = max(dp[n-1][m], dp[n][m-1]);
            dp[n][m] = len;
        }
    }
    return dp[N][M];
}

int lcs(string s, string t){
    int n = s.size(), m = t.size();
    dp.resize(n+1, vector<int>(m+1,0));
    int ans = recc(s, n, t, m);
    dp.clear();
    return ans;
}
//************************************ SPACE OPTIMISATION************************************************************
vector<int>prev, curr;
int recc(string s, int N, string t, int M){
    for(int n=0;n<=N; n++){
        for(int m=0; m<=M; m++){
            if(n==0 or m==0){
                curr[m] = 0;
                continue;
            }
            int len = 0;
            if(s[n-1] == t[m-1]){
                len = prev[m-1]+ 1;
            }
            else len = max(prev[m], curr[m-1]);
            curr[m] = len;
        }
        prev = curr;
    }
    return curr[M];
}

int lcs(string s, string t){
    int n = s.size(), m = t.size();
    prev.resize(m+1, 0);
    curr.resize(m+1, 0);
    int ans = recc(s, n, t, m);
    return ans;
}




int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}