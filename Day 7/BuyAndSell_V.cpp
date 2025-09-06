#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  //<=========RECURSION==========>
//    int solve(int ind, vector<int>&arr,bool buy, int n,int fee){
//     if(ind==n) 
//     return 0;
    
//     int profit=0;
//     if(buy){
//     int include=-arr[ind]+solve(ind+1,arr,!buy,n,fee);
//     int exclude=solve(ind+1,arr,buy,n,fee);

//     profit=max(include,exclude);
//     }

//     else{
//     int include=arr[ind]+solve(ind+1,arr,!buy,n,fee)-fee;
//     int exclude=solve(ind+1,arr,buy,n,fee);

//     profit=max(include,exclude);
//     }
// return profit;
//    }
//     int maxProfit(vector<int>& arr,int fee) {
//       bool buy=true; // if true it means you can buy and if false it means cant buy;
//       int n=arr.size();
//       int profit=0;

//       return solve(0,arr,buy,n,fee);
//     }

    //<=========MEMORIZATION==========>

//    int solve(int ind, vector<int>&arr,bool buy, int n,vector<vector<int>>&dp,int fee){
//     if(ind==n) 
//     return 0;
    
//     if(dp[ind][buy]!=-1)
//     return dp[ind][buy];
    
//     int profit=0;
//     if(buy){
//     int include=-arr[ind]+solve(ind+1,arr,!buy,n,dp,fee);
//     int exclude=solve(ind+1,arr,buy,n,dp,fee);

//     profit=max(include,exclude);
//     }

//     else{
//     int include=arr[ind]+solve(ind+1,arr,!buy,n,dp,fee)-fee;
//     int exclude=solve(ind+1,arr,buy,n,dp,fee);

//     profit=max(include,exclude);
//     }
// return dp[ind][buy]=profit;
//    }
//     int maxProfit(vector<int>& arr,int fee) {
      
//       bool buy=true; // if true it means you can buy and if false it means cant buy;
//       int n=arr.size();
//       vector<vector<int>>dp(n+1,vector<int>(2,-1));  
//       int profit=0;

//       return solve(0,arr,buy,n,dp,fee);
//     }

//<========TABULATION===========>
    //  int maxProfit(vector<int>& arr,int fee) {
    //     int n = arr.size();
    //     if (n == 0) return 0;

        
    //     vector<vector<int>> dp(n+1, vector<int>(2, 0));
    //     for (int ind = n - 1; ind >= 0; --ind) {
        
    //         dp[ind][1] = max(-arr[ind] + dp[ind+1][0], dp[ind+1][1]);
    //         dp[ind][0] = max(arr[ind] + dp[ind+1][1]-fee, dp[ind+1][0]);
    //     }

    //     return dp[0][1];
    // }
    //<=============SPACE OPTI===============>
     int maxProfit(vector<int>& arr,int fee) {
        int n = arr.size();
        if (n == 0) return 0;

        int nextBuy = 0;  
        int nextNotBuy = 0; 

        for (int ind = n - 1; ind >= 0; --ind) {
            int currBuy = max(-arr[ind] + nextNotBuy, nextBuy);
            int currNotBuy = max(arr[ind] + nextBuy-fee, nextNotBuy);

            nextBuy = currBuy;
            nextNotBuy = currNotBuy;
        }

        return nextBuy; 
    }
};