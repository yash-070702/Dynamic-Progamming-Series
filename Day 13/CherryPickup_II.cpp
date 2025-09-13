#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //<==============RECURSION================>

    // int solve(vector<vector<int>>&grid , int row , int c1 , int c2,int m , int n){
    //     if(row>=m || c1>=n || c2>=n || c1<0 || c2<0)
    //     return INT_MIN;

    //     int cherries=0;

    //     if(c1==c2)
    //     cherries+=grid[row][c1];

    //     else
    //     cherries+=(grid[row][c1]+grid[row][c2]);

    //     if(row==m-1)
    //     return cherries;

    //     int best=INT_MIN;

    //     for(int first=-1;first<=1;first++){
    //         for(int sec=-1;sec<=1;sec++){
    //             best=max(best,solve(grid,row+1,c1+first,c2+sec,m,n));
    //         }
    //     }
    //   return cherries + best;
    // }
    
    // int cherryPickup(vector<vector<int>>& grid) {
    //     int n = grid[0].size(); 
    //     int m=grid.size();
    //      return solve(grid,0,0,n-1,m,n);
    // }

    //<========MEMORIZATION=========>

    //   int solve(vector<vector<int>>&grid , int row , int c1 , int c2,int m , int n,vector<vector<vector<int>>>&dp){
    //     if(row>=m || c1>=n || c2>=n || c1<0 || c2<0)
    //     return INT_MIN;

    //     if(dp[row][c1][c2]!=-1)
    //     return dp[row][c1][c2];

    //     int cherries=0;

    //     if(c1==c2)
    //     cherries+=grid[row][c1];

    //     else
    //     cherries+=(grid[row][c1]+grid[row][c2]);

    //     if(row==m-1)
    //     return cherries;

    //     int best=INT_MIN;

    //     for(int first=-1;first<=1;first++){
    //         for(int sec=-1;sec<=1;sec++){
    //             best=max(best,solve(grid,row+1,c1+first,c2+sec,m,n,dp));
    //         }
    //     }
    //   return dp[row][c1][c2]=cherries + best;
    // }
    
    // int cherryPickup(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n = grid[0].size(); 

    //     vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
       
    //      return solve(grid,0,0,n-1,m,n,dp);
    // }

    //<=========TABULATION===========>


    int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

   
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

  
    for (int c1 = 0; c1 < n; c1++) {
        for (int c2 = 0; c2 < n; c2++) {
            if (c1 == c2) dp[m-1][c1][c2] = grid[m-1][c1];
            else dp[m-1][c1][c2] = grid[m-1][c1] + grid[m-1][c2];
        }
    }

   
    for (int row = m-2; row >= 0; row--) {
        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = 0; c2 < n; c2++) {

                int cherries = (c1 == c2) ? grid[row][c1] : (grid[row][c1] + grid[row][c2]);

                int best = INT_MIN;
                for (int first = -1; first <= 1; first++) {
                    for (int sec = -1; sec <= 1; sec++) {
                        int nc1 = c1 + first;
                        int nc2 = c2 + sec;
                        if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                            best = max(best, dp[row+1][nc1][nc2]);
                        }
                    }
                }

                dp[row][c1][c2] = cherries + (best == INT_MIN ? 0 : best);
            }
        }
    }

    return dp[0][0][n-1];
}
};