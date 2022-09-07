// Problem Link - https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
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
long long int tabu(vector<int>&arr, int N){
	int prev1 ,prev2 ,curr; 
	 prev1 = prev2 = curr = arr[0];
	for(int n = 0; n <= N; n++){
		if(n == 0){
			prev1 = arr[0];
			continue;
		}
		if(n == 1){
			prev2 = max(arr[0],arr[1]);
			continue;
		}
		int pick = prev1 + arr[n];
		int npick = prev2;
		curr = max(pick,npick);
		prev1 = prev2;
		prev2 = curr;
	}
    return prev2;
}

long long int houseRobber(vector<int>& arr){
    // Write your code here.
    int n = arr.size();
    if(n == 1) return arr[0];
    vector<int> v1, v2;
    for(int i=0;i<n;i++){
        if(i != 0) v1.push_back(arr[i]);
        if(i != n-1) v2.push_back(arr[i]);
    }
    return max(tabu(v1,n-2),tabu(v2,n-2));
}

int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}