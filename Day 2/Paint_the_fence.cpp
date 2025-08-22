#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    
    // USING MEMORIZATION 
    
    // int solve(int n , int k,vector<int>&dp){
    //     if(n==0)
    //     return 0;
        
    //     if(n==1)
    //     return k;
        
    //     if(n==2)
    //     return k+k*(k-1);
        
    //     if(dp[n]!=-1)
    //     return dp[n];
        
    //     return dp[n]= solve(n-1,k,dp)*(k-1)+solve(n-2,k,dp)*(k-1);
    // }
    // int countWays(int n, int k) {
    //  vector<int>dp(n+1,-1);
    //   return solve(n,k,dp);  
    // }
    
    //USING TABULATION 
    // int countWays(int n , int k){
    //     vector<int>dp(n+1,0);
        
    //     dp[0]=0;
    //     dp[1]=k;
    //     dp[2]=k+k*(k-1);
        
    //     for(int i=3;i<=n;i++){
    //         dp[i]=(k-1)*dp[i-2]+(k-1)*dp[i-1];
    //     }
    //     return dp[n];
    // }
    
    // USING SPACE OPTIMIZATION
    
       int countWays(int n , int k){
        vector<int>dp(n+1,0);
        
        if(n==0)
        return 0;
        
        if(n==1)
        return k;
        
        if(n==2)
        return k+k*(k-1);
        
        int prev=k;
        int curr=k+k*(k-1);
        
        for(int i=3;i<=n;i++){
            
            int ans=(k-1)*prev+(k-1)*curr;
            prev=curr;
            curr=ans;
        }
        return curr;
    }
};