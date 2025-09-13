#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //<=========RECURSIVE==========>


    // int solve(vector<vector<int>>&grid, int r1, int r2, int c1, int c2, int n){
    //     if(r1>=n || r2>=n || c1>=n || c2>=n)
    //     return INT_MIN;

    //     if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
    //     return INT_MIN;

    //     if(r1==n-1 && r2==n-1 && c1==n-1 && c2==n-1)
    //     return grid[r1][c1];

    //     int cherries=0;

    //     if(r1==r2 && c1==c2){
    //     cherries+=grid[r1][c2];
    //     grid[r1][c1]==0;
    //     }

    //     else{
    //     cherries=cherries+grid[r1][c1]+grid[r2][c2];
    //             grid[r1][c1]==grid[r2][c2]==0;
    //     }
    //     int goingBottom=solve(grid,r1+1,r2+1,c1,c2,n);
    //     int goingRight=solve(grid,r1+1,r2,c1,c2+1,n);
    //     int comingUp=solve(grid,r1,r2+1,c1+1,c2,n);
    //     int comingLeft=solve(grid,r1,r2,c1+1,c2+1,n);

    //     int best = max({goingBottom,goingRight,comingUp,comingLeft});
    //      if (best == INT_MIN) return INT_MIN; 

    //      return cherries + best;
    // }
    
    // int cherryPickup(vector<vector<int>>& grid) {
    //     int n=grid.size();

    //     return max(0,solve(grid,0,0,0,0,n));
    // }

    //<========MEMORIZATION========>

    // int solve(vector<vector<int>>&grid, int r1, int r2, int c1, int c2, int n, vector<vector<vector<vector<int>>>>&dp){
    //     if(r1>=n || r2>=n || c1>=n || c2>=n)
    //     return INT_MIN;

    //     if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
    //     return INT_MIN;

    //     if(r1==n-1 && r2==n-1 && c1==n-1 && c2==n-1)
    //     return grid[r1][c1];

    //     if(dp[r1][c1][r2][c2]!=-1)
    //     return dp[r1][c1][r2][c2];

    //     int cherries=0;

    //     if(r1==r2 && c1==c2){
    //     cherries+=grid[r1][c1];
    //     }

    //     else{
    //     cherries=cherries+grid[r1][c1]+grid[r2][c2];
    //     }
    //     int goingBottom=solve(grid,r1+1,r2+1,c1,c2,n,dp);
    //     int goingRight=solve(grid,r1+1,r2,c1,c2+1,n,dp);
    //     int comingUp=solve(grid,r1,r2+1,c1+1,c2,n,dp);
    //     int comingLeft=solve(grid,r1,r2,c1+1,c2+1,n,dp);

    //     int best = max({goingBottom,goingRight,comingUp,comingLeft});
    //      if (best == INT_MIN) 
    //      return dp[r1][c1][r2][c2]=INT_MIN; 

    //      return dp[r1][c1][r2][c2]=cherries + best;
    // }
    
    // int cherryPickup(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
    //     return max(0,solve(grid,0,0,0,0,n,dp));
    // }

    //<=======TABULATION=========>

    int solve(vector<vector<int>>& grid, int r1, int r2, int c1, int c2, int n,
          vector<vector<vector<vector<int>>>>& dp) {
    if (r1 >= n || r2 >= n || c1 >= n || c2 >= n) return INT_MIN;

   
    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;

 
    if (r1 == n - 1 && c1 == n - 1 && r2 == n - 1 && c2 == n - 1)
        return grid[r1][c1];

   
    if (dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];

    
    int cherries = 0;
    if (r1 == r2 && c1 == c2) {
        cherries += grid[r1][c1]; 
    } else {
        cherries += grid[r1][c1] + grid[r2][c2];
    }

   
    int op1 = solve(grid, r1 + 1, r2 + 1, c1, c2, n, dp);   
    int op2 = solve(grid, r1 + 1, r2, c1, c2 + 1, n, dp);   
    int op3 = solve(grid, r1, r2 + 1, c1 + 1, c2, n, dp);  
    int op4 = solve(grid, r1, r2, c1 + 1, c2 + 1, n, dp);  
    int best = max({op1, op2, op3, op4});
    if (best == INT_MIN) 
        return dp[r1][c1][r2][c2] = INT_MIN;

    return dp[r1][c1][r2][c2] = cherries + best;
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<vector<int>>>> dp(
        n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
    int ans = solve(grid, 0, 0, 0, 0, n, dp);
    return max(0, ans);
}
};