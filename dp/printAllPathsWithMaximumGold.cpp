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
class Pair{
public:
    int r,c;
    string psf = "";
    Pair(int r, int c, string pdf){
        this->r = r; this->c = c; this->psf = psf;
    }
};
const int N = 1e4+10;
int mat [N][N];
int dp[N][N];
int main(){
    file_i_o();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            int num;
            cin>>num;
            mat[i][j] = num;
        }
    }
    
    for(int j=m-1; j>=0; j--){
        for(int i=0;i<n; i++){
            if(j==m-1){
                dp[i][j] = mat[i][j];
            }
            else if(i==0){
                dp[i][j] = mat[i][j] + max(dp[i][j+1],dp[i+1][j+1]);
            }
            else if(i==n-1){
                dp[i][j] = mat[i][j] + max(dp[i-1][j+1],dp[i][j+1]); 
            }
            else{
                dp[i][j] = mat[i][j] + max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1])); 
            }
        }
    }

    int maxi = -1;

    // for(int i=0; i<n ; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0; i<n ; i++){
        maxi = max(maxi,dp[i][0]);
    }
    queue<Pair>que;
    for(int i=0; i<n ; i++){
        if(dp[i][0] == maxi){
            string str = "";
            str+=to_string(i);
            que.push(Pair(i,0,"i"));
        }
    }

    while(que.size()){
        Pair par = que.front();
        que.pop();

        if(par.c == m-1){
            cout<<par.psf<<endl;
        }
        else if(par.r == 0){
            int maxi = max(dp[par.r][par.c+1],dp[par.r+1][par.c+1]);

            if(maxi == dp[par.r][par.c+1]){
                par.psf+=" d2";
                que.push(Pair(par.r,par.c+1,par.psf));
            }
            if(maxi == dp[par.r+1][par.c+1]){
                que.push(Pair(par.r+1,par.c+1,par.psf+" d3"));
            }
        }
        else if(par.r == n-1){
            int maxi = max(dp[par.r][par.c+1],dp[par.r+1][par.c+1]);

            if(maxi == dp[par.r][par.c+1]){
                que.push(Pair(par.r,par.c+1,par.psf+" d2"));
            }
            if(maxi == dp[par.r-1][par.c+1]){
                que.push(Pair(par.r-1,par.c+1,par.psf+" d1"));
            }
        }
        else{
            int maxi = max(dp[par.r][par.c+1],max(dp[par.r-1][par.c+1],dp[par.r+1][par.c+1]));

            if(maxi == dp[par.r][par.c+1]){
                que.push(Pair(par.r,par.c+1,par.psf+" d2"));
            }
            if(maxi == dp[par.r-1][par.c+1]){
                que.push(Pair(par.r-1,par.c+1,par.psf+" d1"));
            }
            if(maxi == dp[par.r+1][par.c+1]){
                que.push(Pair(par.r+1,par.c+1,par.psf+" d3"));
            }
        }
    }

    cout<<maxi;
}