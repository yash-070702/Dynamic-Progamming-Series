#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int index, int start) {
        if (index < start) return 0; 
        if (index == start) return nums[start];

        if (dp[index] != -1) return dp[index]; 

        // Choose to rob current house or skip it
        int include = solve(nums, dp, index - 2, start) + nums[index];
        int exclude = solve(nums, dp, index - 1, start);

        return dp[index] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; 
        vector<int> dp1(n, -1), dp2(n, -1);
        
       
        int case1 = solve(nums, dp1, n - 2, 0);

     
        int case2 = solve(nums, dp2, n - 1, 1);

        return max(case1, case2);
    }
};
