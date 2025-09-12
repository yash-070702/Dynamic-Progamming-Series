#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//<======RECURSION=======>

//    int solve(int i , int j , int m , int n , vector<vector<int>>&grid){
//     if(i==m-1 && j==n-1)
//     return grid[i][j];

//     if(i>=m || j>=n)
//     return INT_MAX;

//     int right=solve(i,j+1,m,n,grid);
//     int bottom=solve(i+1,j,m,n,grid);

//     return grid[i][j]+min(right,bottom);
//    }

//    int minPathSum(vector<vector<int>>& grid) {
//     int m=grid.size();
//     int n=grid[0].size();

//     return solve(0,0,m,n,grid);
//    }

 int solve(int i , int j , int m , int n , vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i==m-1 && j==n-1)
    return grid[i][j];

    if(i>=m || j>=n)
    return INT_MAX;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int right=solve(i,j+1,m,n,grid,dp);
    int bottom=solve(i+1,j,m,n,grid,dp);

    return dp[i][j]=grid[i][j]+min(right,bottom);
   }

   int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();

    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

    return solve(0,0,m,n,grid,dp);
   }

//<=======TABULATION========>
//    int minPathSum(vector<vector<int>>& grid) {
//     int m = grid.size();
//     int n = grid[0].size();

//     vector<vector<int>> dp(m, vector<int>(n, 0));

//     dp[0][0] = grid[0][0];

    
//     for (int j = 1; j < n; j++) {
//         dp[0][j] = dp[0][j - 1] + grid[0][j];
//     }

    
//     for (int i = 1; i < m; i++) {
//         dp[i][0] = dp[i - 1][0] + grid[i][0];
//     }

    
//     for (int i = 1; i < m; i++) {
//         for (int j = 1; j < n; j++) {
//             dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }

//     return dp[m - 1][n - 1];
// }
};
