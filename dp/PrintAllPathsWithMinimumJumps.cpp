#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
const int N = 1e3+5;
int dp[N];

int main(){
    file_i_o();
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        int jump;
        cin>>jump;
        arr[i] = jump;
    }

    dp[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        int jump = arr[i];
        if(jump == 0){
            dp[i] = -1;
        }
        int mini = INT_MAX;
        for(int j=1; j<=jump and j+i < n; j++){
            if(dp[i+j] == -1)
                continue;
            mini = min(mini, dp[i+j]);
        }

        dp[i] = mini == INT_MAX ? -1 : mini+1;
    }
    // for(int i=0;i<n;i++){
    //     cout<<dp[i]<<" ";
    // }
    cout<<dp[0];
}