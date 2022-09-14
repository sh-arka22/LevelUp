//Shortest Common Supersequence

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
    int recc(string &s, string &t, int N, int M){
        for(int n = 0; n <= N; n++){
            for(int m = 0; m <= M; m++){
                if(n==0 or m==0){
                    dp[n][m] = 0;
                    continue;
                }
                if(s[n-1] == t[m-1]){
                    dp[n][m] = dp[n-1][m-1] + 1;
                }
                else{
                    dp[n][m] = max(dp[n-1][m], dp[n][m-1]);
                }
            }
        }
        return dp[N][M];
    }

    //printing all supersequence
    void print(string &s, int n, string &t, int m, string sAns, vector<string> &ans){
        if(n==0 and m==0){
            reverse(begin(sAns), end(sAns));
            ans.push_back(sAns);
            return;
        }
        if(n>0 and m>0 and (s[n-1] == t[m-1])){
            sAns += s[n-1];
            print(s, n-1, t, m-1, sAns, ans);
            sAns.pop_back();
        }
        else{
            if(n>0 and m>0 and (dp[n-1][m] > dp[n][m-1])){
                sAns += s[n-1];
                print(s, n-1, t, m, sAns, ans);
                sAns.pop_back();
            }
            else if(n>0 and m>0 and (dp[n-1][m] < dp[n][m-1])){
                sAns += t[m-1];
                print(s, n, t, m-1, sAns, ans);
                sAns.pop_back();
            }
            else{
                if(m>0){
                    sAns += t[m-1];
                    print(s, n, t, m-1, sAns, ans);
                    sAns.pop_back();
                }
                if(n>0){
                    sAns += s[n-1];
                    print(s, n-1, t, m, sAns, ans);
                    sAns.pop_back();
                }
            }
        }
    }

    string shortestSupersequence(string &s, string &t){
        int n = s.size(), m = t.size();
        dp.resize(n+1, vector<int>(m+1,0));
        int ans = recc(s,t, n,  m);
        vector<string> ss;
        print(s, n, t, m, "" ,ss);
        return ss[0];
    }


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}