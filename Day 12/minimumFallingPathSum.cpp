#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//<=======RECURSION========>

// int solve(vector<vector<int>>&matrix,int n , int i, int j){

//      if (i < 0 || j < 0 || i >= n || j >= n) 
//             return INT_MAX;

//         if (i == n - 1) 
//             return matrix[i][j];

   

//      int below=solve(matrix,n,i+1,j);
//      int rightDia=solve(matrix,n,i+1,j+1);
//      int leftDia=solve(matrix,n,i+1,j-1);


//      return matrix[i][j]+min(below,min(rightDia,leftDia));
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//     int n=matrix.size();
//     int ans = INT_MAX;

   
//     for (int j = 0; j < n; j++) {
//         ans = min(ans, solve(matrix, n, 0, j));
//     }

//     return ans;

//     }

//<========MEMORIZATION=========>

// int solve(vector<vector<int>>&matrix,int n , int i, int j,vector<vector<int>>&dp){

//      if (i < 0 || j < 0 || i >= n || j >= n) 
//             return INT_MAX;

//         if (i == n - 1) 
//             return matrix[i][j];

//             if(dp[i][j]!=-1)
//             return dp[i][j];

   

//      int below=solve(matrix,n,i+1,j,dp);
//      int rightDia=solve(matrix,n,i+1,j+1,dp);
//      int leftDia=solve(matrix,n,i+1,j-1,dp);


//      return dp[i][j]= matrix[i][j]+min(below,min(rightDia,leftDia));
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//     int n=matrix.size();
//     int ans = INT_MAX;

//     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

   
//     for (int j = 0; j < n; j++) {
//         ans = min(ans, solve(matrix, n, 0, j,dp));
//     }

//     return ans;

//     }

//<========TABULATION=========>

int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

       
        vector<vector<int>> dp(n, vector<int>(n, 0));

      
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = matrix[n-1][j];
        }

      
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int below = dp[i+1][j];
                int leftDia = (j > 0) ? dp[i+1][j-1] : INT_MAX;
                int rightDia = (j < n-1) ? dp[i+1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min(below, min(leftDia, rightDia));
            }
        }

       
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};