#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//<=======RECURSION========>

// int solve(vector<vector<int>>& matrix, int i, int j, int n) {
//         if (i == n - 1) return matrix[i][j];

//         int ans = INT_MAX;
//         for (int k = 0; k < n; k++) {
//             if (k == j) continue; 
//             ans = min(ans, solve(matrix, i + 1, k, n));
//         }

//         return matrix[i][j] + ans;
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans = INT_MAX;

//         for (int j = 0; j < n; j++) {
//             ans = min(ans, solve(matrix, 0, j, n));
//         }
//         return ans;
//     }

//<========MEMORIZATION==========>

// int solve(vector<vector<int>>& matrix, int i, int j, int n,vector<vector<int>>&dp) {
//         if (i == n - 1) return matrix[i][j];

//         if(dp[i][j]!=-1)
//         return dp[i][j];


//         int ans = INT_MAX;
//         for (int k = 0; k < n; k++) {
//             if (k == j) continue; 
//             ans = min(ans, solve(matrix, i + 1, k, n,dp));
//         }

//         return dp[i][j]=matrix[i][j] + ans;
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans = INT_MAX;
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

//         for (int j = 0; j < n; j++) {
//             ans = min(ans, solve(matrix, 0, j, n,dp));
//         }
//         return ans;
//     }

//<=========TABULATION==========>

   int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int best = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k == j) continue; 
                    best = min(best, dp[i + 1][k]);
                }
                dp[i][j] = matrix[i][j] + best;
            }
        }

      
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};