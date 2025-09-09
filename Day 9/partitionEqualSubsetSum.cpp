#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    
    //<===========RECURSION==========>

    // bool solve(int ind, vector<int>&nums,int n , int sum){
    //     if(ind==n || sum<0)
    //     return false;

    //     if(sum==0)
    //     return true;

    //     bool include=solve(ind+1,nums,n,sum-nums[ind]);
    //     bool exclude=solve(ind+1,nums,n,sum);

    //     return include || exclude;
    // }

    // bool canPartition(vector<int>& nums) {
    //     int sum=0;
    //     for(auto &a :nums)
    //     sum+=a;

    //     if(sum&1)
    //     return false;
    //     int size=nums.size();

    //     return solve(0,nums,size,sum/2);
    // }

    //<=========MEMORIZATION==========>
    
    //  bool solve(int ind, vector<int>&nums,int n , int sum,vector<vector<int>>&dp){
    //     if(ind==n || sum<0)
    //     return false;

    //     if(sum==0)
    //     return true;

    //     if(dp[ind][sum]!=-1)
    //     return dp[ind][sum];

    //     bool include=solve(ind+1,nums,n,sum-nums[ind],dp);
    //     bool exclude=solve(ind+1,nums,n,sum,dp);

    //     return dp[ind][sum]= include || exclude;
    // }
    
    // bool canPartition(vector<int>& nums) {
    //     int sum=0;
    //     for(auto &a :nums)
    //     sum+=a;

    //     if(sum&1)
    //     return false;
    //     int size=nums.size();
    //     vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));

    //     return solve(0,nums,size,sum/2,dp);
    // }

    //<=========TABULATION==========>
    
    
    bool canPartition(vector<int>&nums){

        int sum=0;
        for(auto &a :nums)
        sum+=a;

        if(sum&1)
        return false;
        
        int size=nums.size(); 
        int target=sum/2;

        vector<vector<int>>dp(size+1,vector<int>(target+1,0));

        for(int i=0;i<=size;i++){
            dp[i][0]=1;
        }

        for(int i=size-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                bool incl=0;

                if(j-nums[i]>=0)
                     incl=dp[i+1][j-nums[i]];
                bool excl=dp[i+1][j];

                dp[i][j]=(incl || excl);
            }
        }
       return dp[0][target];
    }

};
