#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //<========RECURSION========>
    
    // vector<int>solve(vector<int>&nums,int prev,int idx,int n){
    // if(idx>=n)
    // return {};

    // vector<int>notTake=solve(nums,prev,idx+1,n);

    // vector<int>take;

    // if(prev==-1 || (nums[idx]%prev==0)){
    //     take=solve(nums,nums[idx],idx+1,n);
    //     take.insert(take.begin(),nums[idx]);
    // }

    // return (take.size()>notTake.size())?take : notTake;
    // }

    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    // int n=nums.size();

    // sort(nums.begin(),nums.end());

    // return solve(nums,-1,0,n);  
    // }

    //<======MEMORIZATION=========>

    //  vector<int> solve(vector<int>& nums, int prevIdx, int idx, int n, vector<vector<vector<int>>>& dp) {
    //     if (idx >= n) return {};

        
    //     if (!dp[idx][prevIdx+1].empty()) return dp[idx][prevIdx+1];

      
    //     vector<int> notTake = solve(nums, prevIdx, idx+1, n, dp);

        
    //     vector<int> take;
    //     if (prevIdx == -1 || nums[idx] % nums[prevIdx] == 0) {
    //         take = solve(nums, idx, idx+1, n, dp);
    //         take.insert(take.begin(), nums[idx]);
    //     }

       
    //     dp[idx][prevIdx+1] = (take.size() > notTake.size()) ? take : notTake;
    //     return dp[idx][prevIdx+1];
    // }

    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());   
    //     int n = nums.size();

        
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1));

    //     return solve(nums, -1, 0, n, dp);
    // }

    //<======TABULATION=======>
    

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);       
        vector<int> parent(n, -1);

        int maxLen = 1;
        int lastIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

     
        vector<int> ans;
        while (lastIndex != -1) {
            ans.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};