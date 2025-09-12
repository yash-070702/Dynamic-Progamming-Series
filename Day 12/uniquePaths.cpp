#include<bits/stdc++.h>
using namespace std;

// User function template in C++

class Solution {
  public:
  
    //<=====RECURSION======>
  
    // int solve(int i , int j , int m , int n){
    //     if(i==m-1 && j==n-1)
    //     return 1;
        
    //     if(i>=m || j>=n)
    //     return 0;
        
    //     int right=solve(i,j+1,m,n);
    //     int bottom=solve(i+1,j,m,n);
        
    //     return right+bottom;
    // }
   
    // int NumberOfPath(int a, int b) {
    //     return solve(0,0,a,b);
    // }
    
    //<=====MEMORIZATION=======>
    
    //  int solve(int i , int j , int m , int n,vector<vector<int>>&dp){
    //     if(i==m-1 && j==n-1)
    //     return 1;
        
    //     if(i>=m || j>=n)
    //     return 0;
        
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
        
    //     int right=solve(i,j+1,m,n,dp);
    //     int bottom=solve(i+1,j,m,n,dp);
        
    //     return dp[i][j]=right+bottom;
    // }
   
    // int NumberOfPath(int a, int b) {
    //     vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
    //     return solve(0,0,a,b,dp);
    // }
    
    //<========TABULATION==========>
    
    int NumberOfPath(int m , int n){
        
        vector<vector<int>> dp(m, vector<int>(n, 0));

  
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
        
    }
};
