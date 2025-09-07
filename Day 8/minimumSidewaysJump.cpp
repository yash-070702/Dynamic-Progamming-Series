#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

      //<=========RECURSION==========>

    // int solve(vector<int>&obstacles, int currLane, int currPos, int n){
    //     if(currPos==n-1)
    //     return 0;

    //     if(obstacles[currPos+1]!=currLane)
    //     return solve(obstacles,currLane,currPos+1,n);
        
    //     int ans=INT_MAX;

    //     for(int i=1;i<=3;i++){
    //         if(currLane!=i && obstacles[currPos]!=i)
    //         ans=min(ans,1+solve(obstacles,i,currPos,n));
    //     }
    //     return ans;
    // }

    // int minSideJumps(vector<int>&obstacles){
    //     int n=obstacles.size();
    //     return solve(obstacles,2,0,n);
    // }
    
    //<==========MEMORIZATION===========>
     
    // int solve(vector<int>& obs, int currlane, int currpos, int n, vector<vector<int>>& dp) {
    //     if (currpos == n - 1)
    //         return 0;

    //     if (dp[currlane][currpos] != -1)
    //         return dp[currlane][currpos];

        
    //     if (obs[currpos + 1] != currlane)
    //         return dp[currlane][currpos] = solve(obs, currlane, currpos + 1, n, dp);

       
    //     int ans = INT_MAX;
    //     for (int i = 1; i <= 3; i++) {
    //         if (currlane != i && obs[currpos] != i) {
    //             ans = min(ans, 1 + solve(obs, i, currpos + 1, n, dp));
    //         }
    //     }

    //     return dp[currlane][currpos] = ans;
    // }

    // int minSideJumps(vector<int>& obstacles) {
    //     int n = obstacles.size();
    //     vector<vector<int>> dp(4, vector<int>(n, -1)); 
    //     return solve(obstacles, 2, 0, n, dp);
    // }

    //<========TABULATION=========>

    int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();

    vector<vector<int>> dp(4, vector<int>(n, INT_MAX));

   
    dp[1][n-1] = dp[2][n-1] = dp[3][n-1] = 0;

    
    for (int currPos = n - 2; currPos >= 0; currPos--) {
        for (int currLane = 1; currLane <= 3; currLane++) {
            if (obstacles[currPos] == currLane) continue; 

            if (obstacles[currPos + 1] != currLane) {
               
                dp[currLane][currPos] = dp[currLane][currPos + 1];
            } else {
              
                int ans = INT_MAX;
                for (int i = 1; i <= 3; i++) {
                    if (i != currLane && obstacles[currPos] != i) {
                        ans = min(ans, 1 + dp[i][currPos + 1]);
                    }
                }
                dp[currLane][currPos] = ans;
            }
        }
    }

    
    return dp[2][0];
}
};
