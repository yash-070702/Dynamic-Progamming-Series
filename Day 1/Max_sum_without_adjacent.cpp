#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
   
   // USING MEMORISATION 
   
   
    // int solve(vector<int>& arr , int n,vector<int>&dp){
    //     if(n<0)
    //     return 0;
        
    //     if(n==0)
    //     return arr[0];
        
    //     if(dp[n]!=-1)
    //     return dp[n];
        
    //     int include=arr[n]+solve(arr,n-2,dp);
    //     int exclude=0+solve(arr,n-1,dp);
        
    //     return dp[n]=max(include,exclude);
    // }
    
    // int findMaxSum(vector<int>& arr) {
    // int n=arr.size();
    // vector<int>dp(n,-1);
    
    // return solve(arr,n-1,dp);
        
    // }
    
    // USING TABULATION
    
    // int findMaxSum(vector<int>& arr){
    //     int n=arr.size();
    //     if(n==0)
    //     return 0;
        
    //     if(n==1)
    //     return arr[0];
        
    //     vector<int>dp(n,-1);
        
    //     dp[0]=arr[0];
    //     dp[1]=max(arr[0],arr[1]);
        
    //     for(int i=2;i<n;i++){
    //         int inc=arr[i]+dp[i-2];
    //         int exc=dp[i-1];
            
    //         dp[i]=max(inc,exc);
    //     }
        
    //     return dp[n-1];
    // }
    
    // USING SPACE OPTIMIZATION
    
    int findMaxSum(vector<int>& arr){
        int n=arr.size();
        if(n==0)
        return 0;
        
        if(n==1)
        return arr[0];
        
        
        
        int prev=arr[0];
        int curr =max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++){
            int inc=arr[i]+prev;
            int exc=curr;
            
            prev=curr;
            curr=max(inc,exc);
        }
        
        return curr;
    }
    
};