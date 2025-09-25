#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // int gcd(int a , int b){
    //     return b == 0 ? a : gcd(b,a%b);
    // }
    
    // int solve(vector<int>&nums,vector<bool>&used,int op){
    //     int n=nums.size();
    //     int maxScore=0;

    //     for(int i=0;i<n;i++){
    //         if(used[i])
    //         continue;

    //         for(int j=i+1;j<n;j++){
    //             if(used[j])
    //             continue;


    //             used[i]=used[j]=true;
    //             int totalScore=op*gcd(nums[i],nums[j])+solve(nums,used,op+1);
    //             maxScore=max(maxScore,totalScore);

    //             used[i]=used[j]=false;

    //         }
    //         break;
    //     }
    //     return maxScore;
    // }
     
    // int maxScore(vector<int>& nums) {
    //      int n = nums.size();
    // vector<bool> used(n, false);
    // return solve(nums, used, 1);
    // }

    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }

    int solve(vector<int>& nums, vector<bool>& used, int op, vector<int>& dp){
        int n = nums.size();
        int mask = 0;


        for(int i = 0; i < n; i++){
            if(used[i]) mask |= (1 << i);
        }

        if(dp[mask] != -1)
            return dp[mask];

        int maxScore = 0;

        for(int i = 0; i < n; i++){
            if(used[i]) continue;

            for(int j = i + 1; j < n; j++){
                if(used[j]) continue;

                used[i] = used[j] = true;
                int totalScore = op * gcd(nums[i], nums[j]) + solve(nums, used, op + 1, dp);
                maxScore = max(maxScore, totalScore);
                used[i] = used[j] = false;
            }
        }

        return dp[mask] = maxScore;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        vector<int> dp(1 << n, -1); 
        return solve(nums, used, 1, dp);
    }

};