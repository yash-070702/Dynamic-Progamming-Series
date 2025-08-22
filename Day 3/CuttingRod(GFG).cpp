#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  //<---------------- USING MEMORIZATION ------------->
  
    // int solve(vector<int> &price , vector<int>& dp , int length){
    //     if(length == 0) 
    //     return 0;
        
    //     if(dp[length] != -1)
    //     return dp[length];
        
    //     int ans = INT_MIN;
        
    //     for(int i = 1; i <= length; i++){
    //         ans = max(ans, price[i-1] + solve(price, dp, length - i));
    //     }
        
    //     return dp[length] = ans;
    // }
    
    // int cutRod(vector<int> &price) {
    //     int n = price.size();
    //     vector<int> dp(n+1, -1);
    //     return solve(price, dp, n);
    // }
    
    //<-----------USING TABULATION------------->
        int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n+1, 0);

     
        for(int i = 1; i <= n; i++) {
            int ans = INT_MIN;
            for(int j = 1; j <= i; j++) {
                ans = max(ans, price[j-1] + dp[i-j]);
            }
            dp[i] = ans;
        }

        return dp[n];
    }
};