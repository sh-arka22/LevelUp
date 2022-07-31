or(int i=n-1;i>=0; i--){
    //     for(int j=m-1; j>=0; j--){
    //         if(j==m-1){
    //             dp[i][j] = mat[i][j];
    //         }
    //         else if(i==0){
    //             dp[i][j] = mat[i][j] + max(dp[i][j+1],dp[i+1][j+1]);
    //         }
    //         else if(i==n-1){
    //             dp[i][j] = mat[i][j] + max(dp[i-1][j+1],dp[i][j+1]); 
    //         }
    //         else{
    //             dp[i][j] = mat[i][j] + max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1])); 
    //         }
    //     }
    // }