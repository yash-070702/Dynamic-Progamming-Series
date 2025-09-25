#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //<=======RECURSION========>

    // int solve(int i , int j , vector<int>&nums1, vector<int>&nums2){
    //     if(i>=nums1.size() || j>=nums2.size())
    //     return 0;

    //     if(nums1[i]==nums2[j])
    //     return 1+solve(i+1,j+1,nums1,nums2);

    //     return max(solve(i,j+1,nums1,nums2),solve(i+1,j,nums1,nums2));
    // }

    // int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    //     return solve(0,0,nums1,nums2);
    // }

    //<=======MEMORIZATION=========>

    // int solve(int i , int j , vector<int>&nums1, vector<int>&nums2,vector<vector<int>>&dp){
    //     if(i>=nums1.size() || j>=nums2.size())
    //     return 0;

    //     if(dp[i][j]!=-1)
    //     return dp[i][j];


    //     if(nums1[i]==nums2[j])
    //     return dp[i][j]=1+solve(i+1,j+1,nums1,nums2,dp);

    //     return dp[i][j]=max(solve(i,j+1,nums1,nums2,dp),solve(i+1,j,nums1,nums2,dp));
    // }

    // int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    //     int n=nums1.size();
    //     int m=nums2.size();

    //     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //     return solve(0,0,nums1,nums2,dp);
    // }
    
    //<======TABULATION======>

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size();
	int m = nums2.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (nums1[i - 1] == nums2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[n][m];
}
};

