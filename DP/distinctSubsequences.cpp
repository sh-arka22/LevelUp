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

int recc(string &s, string &t, int n, int m){
    if(n<0 or m<0){
        if(m<0)return 1;
        if(n<0) return 0;
    }
    int left = 0, right = 0;
    if(s[n] == t[m]){
        left = recc(s, t, n-1, m-1);
    }
    right = recc(s, t, n-1, m);

    return left + right;
}
//************************** TABULATE ************************
vector<vector<long long>>dp;
int recc(string &s, string &t, int N, int M){
    for(int n=0;n<=N;n++){
        for(int m=0;m<=M;m++){
            if(n==0 or m==0){
                if(m==0){
                    dp[n][m] = 1;
                    continue;
                }
                if(n==0){
                    dp[n][m] = 0;
                    continue;
                } 
            }
            int left = 0, right = 0;
            if(s[n-1] == t[m-1]){
                left = dp[n-1][m-1];
            }
            right = dp[n-1][m];
            dp[n][m] = (left+right)%1000000007;
        }
    }
    return dp[N][M];
}
//************************** SPACE OPTIMIZATION  **********************************************************************

vector<int> curr, prev;
int recc(string &s, string &t, int N, int M){
    for(int n=0;n<=N;n++){
        for(int m=0;m<=M;m++){
            if(n==0 or m==0){
                if(m==0){
                    curr[m] = 1;
                    continue;
                }
                if(n==0){
                    curr[m] = 0;
                    continue;
                } 
            }
            int left = 0, right = 0;
            if(s[n-1] == t[m-1]){
                left = prev[m-1];
            }
            right = prev[m];
            curr[m] = (left+right)%1000000007;
        }
        prev = curr;
    }
    return curr[M];
}

//************************************************************************************************

int numDistinct(string s, string t) {
    return recc(s, t, s.size()-1, t.size()-1);
}

int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}