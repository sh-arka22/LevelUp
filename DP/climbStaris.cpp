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

int fibo(int n){
    if(n <= 1) return 1;

    int f0 = 1;
    int f1 = 2;

    for(int i = 3; i <= n; i++){
        int f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    return f1;
}



int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    

    
	return 0;
}