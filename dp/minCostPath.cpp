#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
const int N = 1e3+5;
int dp[N][N];
int mat[N][N];
class Pair{
public:
    int r,c;
    string psf;
    Pair(int r,int c, string psf){
        this->r = r;this->c = c;
        this->psf = psf;
    }
};
int main(){
    file_i_o();
    int n , m;
    cin>>n>>m;

    for(int i=0; i<n ;i++){
        for(int j=0; j<m; j++){
            int cost;
            cin>>cost;
            mat[i][j] = cost;
        }
    }

    for(int i=n-1; i>=0;i--){
        for(int j=m-1; j>=0; j--){
            if(i == n-1 and j == m-1){
                dp[i][j] = mat[i][j];
                continue;
            }
            if(i == n-1){
                dp[i][j] = mat[i][j] + dp[i][j+1];
                continue;
            }
            if(j == m-1){
                dp[i][j] = mat[i][j] + dp[i+1][j];
                continue;
            }
            dp[i][j] = mat[i][j] + min(dp[i][j+1],dp[i+1][j]);
        }
    }
    
    cout<<dp[0][0]<<endl;
    queue<Pair>que;
    que.push(Pair(0,0,""));

    while(que.size()){
        Pair par = que.front();
        que.pop();

        if(par.r == n-1 and par.c == m-1){
            cout<<par.psf<<endl;
        }
        else if(par.r == n-1){
            que.push(Pair(par.r,par.c+1,par.psf+"H"));
        }
        else if(par.c == m-1){
            que.push(Pair(par.r+1,par.c,par.psf+"V"));
        }
        else{
            if(dp[par.r][par.c + 1] < dp[par.r+1][par.c]){
                que.push(Pair(par.r,par.c+1,par.psf+"H"));
            }
            else if(dp[par.r][par.c + 1] > dp[par.r+1][par.c]){
                que.push(Pair(par.r+1,par.c,par.psf+"V"));
            }
            else{
                que.push(Pair(par.r+1,par.c,par.psf+"V"));
                que.push(Pair(par.r,par.c+1,par.psf+"H"));
            }
        }
    }
}