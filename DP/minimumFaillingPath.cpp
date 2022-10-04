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
int dir[3][2] = {{-1,-1},{-1,0},{-1,1}};
int recc(vector<vector<int>>& matrix, int r, int c){
    if(r==0) return matrix[r][c];

    int mini = (int)1e9;
    for(auto &[dr,dc]: dir){
        int x = r+dr, y = c+dc;
        if(x<0 or y<0 or x>=matrix.size() or y>=matrix[0].size()) continue;
        mini = min(mini,recc(matrix,x,y));
    }
    return mini+matrix[r][c];
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int r = matrix.size(), c = matrix[0].size();
    int mini = (int)1e9;
    for(int j=c-1;j>=0;j--){
        mini = min(mini,recc(matrix,r-1,j));
    }
    return mini;
}

//************************************************************************************************

int dir[3][2] = {{-1,-1},{-1,0},{-1,1}};
vector<vector<int>>dp;
int recc(vector<vector<int>>& matrix, int R, int C){
    for(int r=0;r<=R;r++){
        for(int c=0;c<=C;c++){
            if(r==0){
                dp[r][c] = matrix[r][c];;
                continue;
            }
            int mini = (int)1e9;
            for(auto &[dr,dc]: dir){
                int x = r+dr, y = c+dc;
                if(x<0 or y<0 or x>=matrix.size() or y>=matrix[0].size()) continue;
                mini = min(mini,dp[x][y]);
            }
            dp[r][c] = mini+matrix[r][c];
        }
    }
    return dp[R][C];
}
// int print(vector<vector<int>>& matrix, int r, int c){
//     if(r==0) return matrix[r][c];

//     int mini = (int)1e9;
//     for(auto &[dr,dc]: dir){
//         int x = r+dr, y = c+dc;
//         if(x<0 or y<0 or x>=matrix.size() or y>=matrix[0].size()) continue;
//         mini = min(mini,recc(matrix,x,y));
//     }
//     return mini+matrix[r][c];
// }

int minFallingPathSum(vector<vector<int>> matrix) {
    int r = matrix.size(), c = matrix[0].size();
    dp.resize(r,vector<int>(c));
    int mini = (int)1e9;
    int si, sj;
    for(int j=c-1;j>=0;j--){
        int call = recc(matrix,r-1,j);
        if(call<mini){
            mini = call;
            int si = r-1, sj = j;
        }
    }
    return mini;
}



int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    vector<vector<int>>matrix = {{1, 2, 3},
                                { 4, 5, 6},
                                { 7, 8, 9}};
    cout<<minFallingPathSum(matrix)<<endl;
    for(auto it:dp){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
	return 0;
}