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

int recc(vector<int>& cuts, int si, int ei){
    if(ei-si == 1) return 0;

    int mini = (int)1e9;
    for(int cut = si+1; cut<ei; cut++){
        int cost = cuts[ei] - cuts[si] + recc(cuts, si, cut) + recc(cuts, cut, ei);
        mini = min(mini, cost);
    }
    return mini;
}

int tabu(vector<int>& cuts, int SI, int EI){
    for(int gap=0;gap<=EI ;gap++){
        for(int si = SI, ei=gap; ei<=EI; si++, ei++){
            if(ei-si == 1){
                dp[si][ei] = 0;
                continue;
            }
            int mini = (int)1e9;
            for(int cut = si+1; cut<ei; cut++){
                int cost = cuts[ei] - cuts[si] + dp[si][cut] + dp[cut][ei];
                mini = min(mini, cost);
            }
            dp[si][ei] = mini;
       }
    }
    return dp[SI][EI];
}



int minCost(int n, vector<int>& cuts) {
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    int n = cuts.size();
    return recc(cuts, 0, n-1);
}

int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}