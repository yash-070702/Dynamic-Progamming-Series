#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //<======RECURSION=======>
     
    // int solve(int i, vector<int>& stoneValue) {
    //     int n = stoneValue.size();
    //     if (i >= n) return 0;

    //     int take = 0;
    //     int best = INT_MIN;

       
    //     for (int x = 0; x < 3 && i + x < n; x++) {
    //         take += stoneValue[i + x];
    //         best = max(best, take - solve(i + x + 1, stoneValue));
    //     }
    //     return best;
    // }

    // string stoneGameIII(vector<int>& stoneValue) {
    //     int diff = solve(0, stoneValue);
    //     if (diff > 0) return "Alice";
    //     if (diff < 0) return "Bob";
    //     return "Tie";
    // }

    //<====MEMORIZATION=====>

    // int solve(int i, vector<int>& stoneValue,vector<int>&dp) {
    //     int n = stoneValue.size();
    //     if (i >= n) return 0;

    //     if(dp[i]!=-1)
    //     return dp[i];

    //     int take = 0;
    //     int best = INT_MIN;

       
    //     for (int x = 0; x < 3 && i + x < n; x++) {
    //         take += stoneValue[i + x];
    //         best = max(best, take - solve(i + x + 1, stoneValue,dp));
    //     }
    //     return dp[i]=best;
    // }

    // string stoneGameIII(vector<int>& stoneValue) {

    //     int n = stoneValue.size();
    //     vector<int>dp(n+1,-1);
    //     int diff = solve(0, stoneValue,dp);
    //     if (diff > 0) return "Alice";
    //     if (diff < 0) return "Bob";
    //     return "Tie";
    // }

    //<=====TABULATION=====>

     string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0); 

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            int best = INT_MIN;
            for (int x = 0; x < 3 && i + x < n; x++) {
                take += stoneValue[i + x];
                best = max(best, take - dp[i + x + 1]);
            }
            dp[i] = best;
        }

        int diff = dp[0];
        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};