#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //<=======RECURSION========>

    // int solve(int i , int j , vector<int>&piles){
    //     if(i>j)
    //     return 0;
        
    //     return max((piles[i]+solve(i+2,j,piles)),(piles[j]+solve(i,j-2,piles)));
        
    // } 

    // bool stoneGame(vector<int>& piles) {
    //     int n=piles.size();
    //     int ans=solve(0,n-1,piles);
    //     int total=0;

    //     for(auto it :piles)
    //     total+=it;
    
    //     return total/2<ans;
    // }

    //<======TABULATION=======>

    // int solve(int i , int j , vector<int>&piles,vector<vector<int>>&dp){
    //     if(i>j)
    //     return 0;

    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
        
    //     return dp[i][j]=max((piles[i]+solve(i+2,j,piles,dp)),(piles[j]+solve(i,j-2,piles,dp)));
        
    // } 

    // bool stoneGame(vector<int>& piles) {
    //     int n=piles.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     int ans=solve(0,n-1,piles,dp);
    //     int total=0;

    //     for(auto it :piles)
    //     total+=it;
     

    //     return total/2<ans;

    // }

    //<======TABULATION=======>
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

     
        for(int i = 0; i < n; i++)
            dp[i][i] = piles[i];

       
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

               
                int pickLeft = piles[i];
                if(i + 2 <= j) pickLeft += dp[i+2][j]; 
                int pickRight = piles[j];
                if(i <= j-2) pickRight += dp[i][j-2];

                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        int ans = dp[0][n-1];

        int total = 0;
        for(auto x : piles) total += x;

        return ans > total / 2;
    }
};

