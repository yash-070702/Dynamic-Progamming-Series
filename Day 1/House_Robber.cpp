#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//USING MEMORIZATION

// int solve(vector<int>&nums,int n, vector<int>&dp){
//     if(n<0)
//     return 0;

//     if(n==0)
//     return nums[0];

//     if(dp[n]!=-1)
//     return dp[n];

//     int include=solve(nums,n-2,dp)+nums[n];
//     int exclude=solve(nums,n-1,dp);

//     dp[n]=max(include,exclude);
//     return dp[n];
// }
//     int rob(vector<int>& nums) {
//     int n = nums.size();
//     vector<int>dp(n,-1);
//     int answer=solve(nums,n-1,dp);

//     return answer;
//     }


//USING TABULATION

// int rob(vector<int>&nums){

// int n=nums.size();
// vector<int>dp(n,0);
// if(n<=0)
// return 0;

// if(n==1)
// return nums[0];

// dp[0]=nums[0];
// dp[1]=max(nums[0],nums[1]);

// for(int i=2;i<n;i++){
//     int inc=nums[i]+dp[i-2];
//     int exc=dp[i-1];

//     dp[i]=max(inc,exc);
// }

// return dp[n-1];
// }

//SPACE OPTIMIZATION

int rob(vector<int>&nums){

int n=nums.size();

if(n<=0)
return 0;

if(n==1)
return nums[0];

int prev=nums[0];
int curr=max(nums[0],nums[1]);

for(int i=2;i<n;i++){
    int inc=nums[i]+prev;
    int exc=curr;
    prev=curr;
    curr=max(inc,exc);
}

return curr;
}

};