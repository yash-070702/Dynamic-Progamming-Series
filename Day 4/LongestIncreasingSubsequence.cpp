#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    // <----------RECURSION------------>
    
    // int solve(int ind , vector<int>&arr , int prev){
    //     if(ind==arr.size())
    //     return 0;
        
        
    //     int exc=solve(ind+1,arr,prev);
    //     int inc=0;
        
    //     if(arr[ind]>prev){
    //         prev=arr[ind];
    //         inc=1+solve(ind+1,arr,prev);
    //     }
        
    //     return max(inc,exc);
    // }
    
    // int lis(vector<int>& arr) {
        
    //     int n=arr.size();
    //     int prev=INT_MIN;
    //     return solve(0,arr,prev);
    // }
    
    //<===========MEMORIZATION==========>
    
  int solve(vector<int>&nums,int curr, int prev, vector<vector<int>>&dp){
        if(curr==nums.size())
        return 0;

        if(dp[curr][prev+1]!=-1)
        return dp[curr][prev+1];

        int include=0;
        if(prev==-1 || nums[curr]>nums[prev])
        include=1+solve(nums,curr+1,curr,dp);

        int exclude=solve(nums,curr+1,prev,dp);

        return dp[curr][prev+1]=max(include,exclude);
    }

    int lis(vector<int>& nums) {
        int n=nums.size();
      vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
      }
    
    
};