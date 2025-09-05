#include <bits/stdc++.h>
using namespace std;

//<===========RECURSION============>

// class Solution {
//     int dfs(int i, const vector<int>& arr, int diff) {
//         int best = 1;
//         for (int j = i - 1; j >= 0; --j) {
//             if (arr[i] - arr[j] == diff) {
//                 best = max(best, 1 + dfs(j, arr, diff));
//             }
//         }
//         return best;
//     }

// public:
//     int longestSubsequence(vector<int>& arr, int difference) {
//         int n = (int)arr.size();
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             ans = max(ans, dfs(i, arr, difference));
//         }
//         return ans;
//     }
// };

//<===========MEMORIZATION===============>

// class Solution {
//     int dfs(int i, const vector<int>& arr, int diff, vector<int>& memo) {
//         if (memo[i] != -1) return memo[i];

//         int best = 1; // subsequence with only arr[i]
//         for (int j = i - 1; j >= 0; --j) {
//             if (arr[i] - arr[j] == diff) {
//                 best = max(best, 1 + dfs(j, arr, diff, memo));
//             }
//         }
//         return memo[i] = best;
//     }

// public:
//     int longestSubsequence(vector<int>& arr, int difference) {
//         int n = (int)arr.size();
//         vector<int> memo(n, -1);
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             ans = max(ans, dfs(i, arr, difference, memo));
//         }
//         return ans;
//     }
// };

//<===========TABULATION============>

class Solution{
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans=0;
        unordered_map<int,int>dp;

        for(int i=0;i<arr.size();i++){
            int temp=arr[i]-difference;
            int tempAns=0;

            if(dp.count(temp))
            tempAns=dp[temp];

            dp[arr[i]]=1+tempAns;

            ans=max(ans,dp[arr[i]]);
        }
      return ans;
        
    }
};
