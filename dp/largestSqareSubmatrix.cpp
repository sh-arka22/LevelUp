#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main(){
    file_i_o();
    int n, m;
    cin>>n>>m;
    vector<vector<int>>dp(n,vector<int>(m,0)), mat(n,vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int num;
            cin>>num;
            mat[i][j] = num;
            // cout<<mat[i][j]<<endl;
        }
    }

    int res = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 or j==0){
                res = max(res,mat[i][j]);
                continue;
            }
            if(mat[i][j] == 0)
                continue;
            mat[i][j] += min(mat[i-1][j], min(mat[i-1][j-1], mat[i][j-1]));
            res = max(res,mat[i][j]);
        }
    }
    cout<<res<<endl;
}

/**
0 1 0 1 0 1 
1 0 1 0 1 0 
0 1 1 1 1 0 
0 0 1 1 1 0 
1 1 1 1 1 1
 */