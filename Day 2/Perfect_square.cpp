#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    // <---------------USING MEMORIZATI0N------------------->
  
    // int solve(int n ,vector<int>&dp){
    //     if(n==0 || n==1 || n==2)
    //     return n;
        
    //     if(dp[n]!=-1)
    //     return dp[n];
        
    //     int ans=INT_MAX;
        
    //     for(int i=1;i*i<=n;i++){
    //     ans=min(ans,1+solve(n-i*i,dp));
    //     }
    //     return dp[n]=ans;
        
    // }
    
    // int MinSquares(int n) {
    //     vector<int>dp(n+1,-1);
        
    //     return solve(n,dp);
        
    // }
    
    //<--------------- USING TABULATION--------------> 
    int MinSquares(int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++){
            for(int j=1;j*j<=i;j++){
              dp[i]=min(dp[i],1+dp[i-j*j]);  
            }
        }
        return dp[n];
    }
};