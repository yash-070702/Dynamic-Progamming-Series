#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//<=======RECURSION========>
  
//   bool solve(vector<int>&nums,int ind,int n){
//     if(ind==n-1)
//     return true;

//     bool ans=false;

//     for(int curr=1;curr<=nums[ind];curr++){
//         ans=ans||solve(nums,ind+curr,n);
//     }
//     return ans;
//   }
    
//     bool canJump(vector<int>& nums) {
//         int n= nums.size();

//         if(n==0 || n==1)
//         return true;

//         return solve(nums,0,n);
//     }

//<=====MEMORIZATION======>

//  bool solve(vector<int>&nums,int ind,int n,vector<int>&dp){
//     if(ind==n-1)
//     return true;

//     if(dp[ind]!=-1)
//     return dp[ind];
   
//     bool ans=false;

//     for(int curr=1;curr<=nums[ind];curr++){
//         ans=ans||solve(nums,ind+curr,n,dp);
//     }
//     return dp[ind]=ans;
//   }
    
//     bool canJump(vector<int>& nums) {
//         int n= nums.size();

//         if(n==0)
//         return true;

//         vector<int>dp(n+1,-1);

//         return solve(nums,0,n,dp);
//     }



//<======TABULATION=======>

    bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false);

    dp[n-1] = true; 

    for (int i = n - 2; i >= 0; i--) {
        int furthestJump = min(i + nums[i], n - 1);
        for (int j = i + 1; j <= furthestJump; j++) {
            if (dp[j]) {
                dp[i] = true;
                break; 
            }
        }
    }

    return dp[0]; 
}
};