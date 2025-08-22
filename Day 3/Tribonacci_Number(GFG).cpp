#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
  // <---------------- USING MEMORIZATION ------------->
    // int solve(int n , vector<int>&dp){
    //   if (n == 0) 
    //     return 0;
      
    //   if (n == 1 || n == 2) 
    //   return 1;
        
    //     if(dp[n]!=-1)
    //     return dp[n];
        
    //     return dp[n]=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
    // }
    
    // int nthTribonacci(int n) {
    // vector<int>dp(n+1,-1);
    
    // return solve(n,dp);
        
    // }

    //<-----------USING TABULATION------------->
    int nthTribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }

    //<--------------- USING SPACE OPTIMIZATION------------------->
    // int nthTribonacci(int n) {
    //     if (n == 0) return 0;
    //     if (n == 1 || n == 2) return 1;

    //     int a = 0, b = 1, c = 1, d;
    //     for (int i = 3; i <= n; i++) {
    //         d = a + b + c;
    //         a = b;
    //         b = c;
    //         c = d;
    //     }
    //     return c;
    // }
};
