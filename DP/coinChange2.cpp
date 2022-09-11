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

long recc(int arr[], int n, int val){
    if(n == 0){
        if(val%arr[0] == 0) return 1;
        return 0;
    }
    long count = 0;
    if(arr[n]<=val){
        count = recc(arr, n, val-arr[n]);
    }
    count+= recc(arr, n-1, val);

    return count;
}

long countWaysToMakeChange(){
    //Write your code here
    int denominations[] = {1, 2, 3 ,4, 5, 6, 7 ,8, 9 ,10};
    return recc(denominations,9, 1000);
}



int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    
    cout<<countWaysToMakeChange();
    
	return 0;
}