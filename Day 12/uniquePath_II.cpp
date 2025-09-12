#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     
    //  <==========RECURSION===========>
      
    //  int solve(int i , int j , int m , int n,vector<vector<int>>&grid){
    //     if(i==m-1 && j==n-1 && grid[i][j]==0)
    //     return 1;
        
    //     if(i>=m || j>=n)
    //     return 0;
        
    //     if(grid[i][j]==1)
    //     return 0;
        
    //     int right=solve(i,j+1,m,n,grid);
    //     int bottom=solve(i+1,j,m,n,grid);
        
    //     return right+bottom;
    // }
   
    //  int uniquePathsWithObstacles(vector<vector<int>>&grid) {
    //     int a=grid.size();
    //     int b=grid[0].size();

    //     return solve(0,0,a,b,grid);
    // }

     
    //  <=============MEMORIZATION=============>

    //  int solve(int i , int j , int m , int n,vector<vector<int>>&dp,vector<vector<int>>&grid){
    //     if(i==m-1 && j==n-1 && grid[i][j]==0)
    //     return 1;
        
    //     if(i>=m || j>=n)
    //     return 0;
        
    //     if(grid[i][j]==1)
    //     return 0;
        
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
        
    //     int right=solve(i,j+1,m,n,dp,grid);
    //     int bottom=solve(i+1,j,m,n,dp,grid);
        
    //     return dp[i][j]=right+bottom;
    // }
   
    //  int uniquePathsWithObstacles(vector<vector<int>>&grid) {
    //        int a=grid.size();
    //        int b=grid[0].size();
    //     vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
    //     return solve(0,0,a,b,dp,grid);
    // }

    //<========TABULATION===========>
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0; 

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1; 

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0; 
                } else {
                    if (i > 0) dp[i][j] += dp[i-1][j]; 
                    if (j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1]; 
    }
};
