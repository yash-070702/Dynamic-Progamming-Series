#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    //<---------------MEMORIZATION--------------->
  
    // int solve(vector<vector<int>>&mat,int n , int m,vector<vector<int>>&dp){
    //     if(n<0 || m<0)
    //         return 0;
        
    //     if(dp[n][m]!=-1)
    //         return dp[n][m];
        
    //     int up = solve(mat, n-1, m, dp);
    //     int dia = solve(mat, n-1, m-1, dp);
    //     int left = solve(mat, n, m-1, dp);
        
    //     if(mat[n][m] == 1)
    //         dp[n][m] = 1 + min(up, min(dia, left));
    //     else
    //         dp[n][m] = 0;
        
    //     return dp[n][m];
    // }
    
    // int maxSquare(vector<vector<int>>& mat) {
    //     int n = mat.size();
    //     int m = mat[0].size();
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
        
    //     int ans = 0;
    //     for(int i = 0; i < n; i++){
    //         for(int j = 0; j < m; j++){
    //             ans = max(ans, solve(mat, i, j, dp));
    //         }
    //     }
    //     return ans;
    // }
    
    
    //<------------------TABULATION-------------->
    
     int maxSquare(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = mat[i][j];
                } else if (mat[i][j] == 1) {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                } else {
                    dp[i][j] = 0;
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }

     //<------------------SPACE OPTIMIZATION--------------->
    
    // int maxSquare(vector<vector<int>>& mat) {
    //     int n = mat.size();
    //     int m = mat[0].size();
        
    //     vector<int> prev(m, 0), curr(m, 0);
    //     int ans = 0;
        
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (i == 0 || j == 0) {
    //                 curr[j] = mat[i][j];
    //             } else if (mat[i][j] == 1) {
    //                 curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
    //             } else {
    //                 curr[j] = 0;
    //             }
    //             ans = max(ans, curr[j]);
    //         }
    //         prev = curr; 
    //     }
    //     return ans;
    // }
};