#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //<======RECURSION=======>

    // int solve(bool buy, int ind, vector<int>&prices,int n){
    //  if(ind>=n){
    //     return 0;
    //  }

    //  if(buy){
    //     int buying=-prices[ind]+solve(false,ind+1,prices,n);
    //     int exclude=solve(buy,ind+1,prices,n);

    //     return max(buying,exclude);
    //  }
     
    //  if(!buy){
    //     int selling=prices[ind]+solve(true,ind+2,prices,n);
    //     int exclude=solve(buy,ind+1,prices,n);

    //     return max(selling,exclude);
    //  }
    //  return 1;
    // }

    // int maxProfit(vector<int>& prices) {
    // return solve(true,0,prices,prices.size());
    // }

    //<========MEMORIZATION========>

    // int solve(bool buy, int ind, vector<int>&prices,int n,vector<vector<int>>&dp){
    //  if(ind>=n){
    //     return 0;
    //  }

    //  if(dp[ind][buy]!=-1)
    //  return dp[ind][buy];

    //  if(buy){
    //     int buying=-prices[ind]+solve(false,ind+1,prices,n,dp);
    //     int exclude=solve(buy,ind+1,prices,n,dp);

    //     return dp[ind][buy]=max(buying,exclude);
    //  }
     
    //  if(!buy){
    //     int selling=prices[ind]+solve(true,ind+2,prices,n,dp);
    //     int exclude=solve(buy,ind+1,prices,n,dp);

    //     return dp[ind][buy]=max(selling,exclude);
    //  }
    //  return 1;
    // }

    // int maxProfit(vector<int>& prices) {
    // int n=prices.size();
    // vector<vector<int>>dp(n+1,vector<int>(2,-1));
    // return solve(true,0,prices,n,dp);
    // }

    //<=====TABULATION=======>

     int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0)); 

        for(int ind = n-1; ind >= 0; ind--) {
           
            dp[ind][1] = max(-prices[ind] + dp[ind+1][0],
                             dp[ind+1][1]);

            dp[ind][0] = max(prices[ind] + dp[ind+2][1],
                             dp[ind+1][0]);
        }

        return dp[0][1];
    }
};