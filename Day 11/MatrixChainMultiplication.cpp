#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
     
    //<========RECURSION==========> 
     
    // int solve(vector<int>&arr, int i , int j){
    //     if(i==j)
    //     return 0;
        
        
        
    //     int ans=INT_MAX;
        
    //     for(int k=i;k<j;k++){
    //         int minCost=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            
    //         ans=min(ans,minCost);
    //     }
        
    //     return ans;
    // }
    
    // int matrixMultiplication(vector<int> &arr) {
        
    //     int size=arr.size();
    //   return solve(arr,1,size-1);
       
        
    // } 
    
    //<=========MEMORIZATION==========>
     
    // int solve(vector<int>&arr, int i , int j,vector<vector<int>>&dp){
    //     if(i==j)
    //     return 0;
        
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
        
    //     int ans=INT_MAX;
        
    //     for(int k=i;k<j;k++){
    //         int minCost=solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
            
    //         ans=min(ans,minCost);
    //     }
        
    //     return dp[i][j]=ans;
    // }
    
    // int matrixMultiplication(vector<int> &arr) {
        
    //     int size=arr.size();
    //     vector<vector<int>>dp(size+1,vector<int>(size+1,-1));
        
    //   return solve(arr,1,size-1,dp);
       
        
    // }
    
    //<======TABULATION========>
    
    int matrixMultiplication(vector<int> &arr) {
        
    int n = arr.size();

  
    vector<vector<int>> dp(n, vector<int>(n, 0));


    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n-1];
}

};