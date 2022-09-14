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
void print(vector<vector<int>>&dp){
    for(auto vv:dp){
        for(auto it:vv) cout<<it<<" ";
        cout<<endl;
    }
}
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

void print(string s, int n, string t, int m, string sAns, vector<string> &ans){
    if(n==0 or m==0){
        reverse(begin(sAns), end(sAns));
        ans.push_back(sAns);
        return;
    }
    if(s[n-1] == t[m-1]){
        sAns += s[n-1];
        print(s, n-1, t, m-1, sAns, ans);
        sAns.pop_back();
    }
    else{
        if(dp[n-1][m] > dp[n][m-1]){
            print(s, n-1, t, m, sAns, ans);
        }
        else if(dp[n-1][m] < dp[n][m-1]){
            print(s, n, t, m-1, sAns, ans);
        }
        else{
            print(s, n, t, m-1, sAns, ans);
            print(s, n-1, t, m, sAns, ans);
        }
    }
}

vector<string> all_longest_common_subsequences(string s, string t){
    int n = s.size(), m = t.size();
    vector<string>res;
    print(s, n, t, m, "", res);
    for(auto s:res){
        cout<<s<<endl;
    }
    return res;
}
int lcs(string s, string t){
    int n = s.size(), m = t.size();
    dp.resize(n+1, vector<int>(m+1,0));
    int ans = recc(s, n, t, m);
    vector<string> res = all_longest_common_subsequences(s, t);
    return ans;
}

int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    string s1, s2;
    cin>>s1>>s2;
    cout<<lcs(s1, s2)<<endl;
    print(dp);
	return 0;
}