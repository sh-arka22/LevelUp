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
int recc(int n, int w, vector<int> &profit, vector<int> &weight){
    if(n==0){
        return (w/weight[0])*profit[0];
    }
    int pick = 0;
    if(w>=weight[n]){
        pick = recc(n, w-weight[n],profit,weight) + profit[n];
    }
    int notPick = recc(n-1, w, profit, weight);

    return max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    return recc(n-1, w, profit, weight);
}
//**************************************SPACE OPTIMISATION********************************************
#include<vector>
int recc2(int N, int W, vector<int> &profit, vector<int> &weight,vector<int>&curr){
    for(int n=0;n<=N;n++){
        for(int w=0;w<=W;w++){
            if(n==0){
                curr[w] = (w/weight[0])*profit[0];
                continue;
            }
            int pick = 0;
            if(w>=weight[n]){
                pick = curr[w-weight[n]]+ profit[n];
            }
            int notPick = curr[w];

            curr[w] =max(pick, notPick);
         }
    }
    return curr[W];
}
//****************STRIVER WAY SPACE OPTIMISATION********************************************************************************
int recc(int N, int W, vector<int> &profit, vector<int> &weight,vector<int>&curr,vector<int>&prev){
    for(int n=0;n<=N;n++){
        for(int w=0;w<=W;w++){
            if(n==0){
                curr[w] = (w/weight[0])*profit[0];
                continue;
            }
            int pick = 0;
            if(w>=weight[n]){
                pick = curr[w-weight[n]]+ profit[n];
            }
            int notPick = prev[w];

            curr[w] =max(pick, notPick);
         }
        prev = curr;
    }
    return prev[W];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int>curr(w+1, 0);
    vector<int>prev(w+1, 0);
    int ans = recc(n-1, w, profit, weight, curr, prev);
    return ans;
}
//********************************************************************************************************
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int>curr(w+1, 0);
    int ans = recc2(n-1, w, profit, weight, curr);
    return ans;
}

int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}