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

const int N= 1e3+5;
int dp[N][N];

int main(){
    file_i_o();
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        int coin;
        cin>>coin;
        arr[i]= coin;
    }
    int tar;
    cin>>tar;
    for(int i=0;i<n;i++){
        for(int s=0;s<=tar;s++){
            if(s == 0){
                dp[i][s] = 1;
                continue;
            }
            if(i==0){
                if(arr[i] == s){
                    dp[i][s] = 1;
                }
                continue;
            }
            int included = 0;
            if(s>=arr[i]){
                included = dp[i-1][s-arr[i]];
            }

            int notIncluded = dp[i-1][s];

            dp[i][s] += (included + notIncluded);
        }
    }
    cout<<dp[n-1][tar]<<endl;
    cout<<(dp[n-1][tar] == 1 ? "true" : "false");
}