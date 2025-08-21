#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
//  USING MEMORIZATION


//   int solve(int n , int x , int y , int z , vector<int>&dp){
//       if(n==0)
//       return 0;
      
//       if(n<0)
//       return INT_MIN;
      
//       if(dp[n]!=-1)
//       return dp[n];
      
//       int x_cut=1+solve(n-x,x,y,z,dp);
//       int y_cut=1+solve(n-y,x,y,z,dp);
//       int z_cut=1+solve(n-z,x,y,z,dp);
      
//       return dp[n]=max(x_cut,max(y_cut,z_cut));
      
//   }

//     int maximizeTheCuts(int n, int x, int y, int z) {
        
//       vector<int>dp(n+1,-1);
//              int ans = solve(n, x, y, z, dp);
//         return (ans < 0) ? 0 : ans; 
//     }

//USING TABULATION

int maximizeTheCuts(int n, int x, int y, int z) {
    
    vector<int>dp(n+1,INT_MIN);
    
    dp[0]=0;
    
    for(int i=1;i<=n;i++){
        
        int x_cut=INT_MIN;
        if (i - x >= 0 && dp[i - x] != INT_MIN) 
        x_cut=dp[i-x]+1;
        
        int y_cut=INT_MIN;
        if (i - y >= 0 && dp[i - y] != INT_MIN) 
        y_cut=dp[i-y]+1;
        
        int z_cut=INT_MIN;
        
        if (i - z >= 0 && dp[i - z] != INT_MIN) 
        z_cut=dp[i-z]+1;
        
        dp[i]=max(dp[i],max(x_cut,max(y_cut,z_cut)));
    }
    if(dp[n]<0)
    return 0;
    
    return dp[n];
}
};