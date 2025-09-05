#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

  //***<======REMEBER KI EK LIMIT JAB KAM HOGI JAB SUCCESSFULLY EK BUY AND SELL COMPLETE HOGA=====>***

    //<=========RECURSION==========>
//    int solve(int ind, vector<int>&arr,bool buy, int n,int limit){
//     if(ind==n) 
//     return 0;

//     if(limit==0)
//     return 0;
    
//     int profit=0;
//     if(buy){
//     int include=-arr[ind]+solve(ind+1,arr,!buy,n,limit);
//     int exclude=solve(ind+1,arr,buy,n,limit);

//     profit=max(include,exclude);
//     }

//     else{
//     int include=arr[ind]+solve(ind+1,arr,!buy,n,limit-1);
//     int exclude=solve(ind+1,arr,buy,n,limit);

//     profit=max(include,exclude);
//     }
// return profit;
//    }
//     int maxProfit(int k , vector<int>& arr) {
//       bool buy=true; // if true it means you can buy and if false it means cant buy;
//       int n=arr.size();
//       int profit=0;

//       return solve(0,arr,buy,n,k);
//     }

//<=========MEMORIZATION==========>

//    int solve(int ind, vector<int>&arr,bool buy, int n,vector<vector<vector<int>>>&dp,int limit){
//     if(ind==n) 
//     return 0;

//     if(limit==0)
//     return 0;
    
//     if(dp[ind][buy][limit]!=-1)
//     return dp[ind][buy][limit];
    
//     int profit=0;
//     if(buy){
//     int include=-arr[ind]+solve(ind+1,arr,!buy,n,dp,limit);
//     int exclude=solve(ind+1,arr,buy,n,dp,limit);

//     profit=max(include,exclude);
//     }

//     else{
//     int include=arr[ind]+solve(ind+1,arr,!buy,n,dp,limit-1);
//     int exclude=solve(ind+1,arr,buy,n,dp,limit);

//     profit=max(include,exclude);
//     }
// return dp[ind][buy][limit]=profit;
//    }
//     int maxProfit(int k , vector<int>& arr) {
      
//       bool buy=true; // if true it means you can buy and if false it means cant buy;
//       int n=arr.size();
//       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));  
//       int profit=0;

//       return solve(0,arr,buy,n,dp,2);
//     }

//  <===========TABULISATION=============>
// int maxProfit(int k , vector<int>& arr) {
//         int n = arr.size();
//         if (n == 0) return 0;

//       
//         vector<vector<vector<int>>> dp(n + 1,
//             vector<vector<int>>(2, vector<int>(k + 1, 0)));

     

//         for (int ind = n - 1; ind >= 0; --ind) {
//             for (int limit = 1; limit <= k; ++limit) {
               
//                 dp[ind][1][limit] = max(-arr[ind] + dp[ind + 1][0][limit],
//                                         dp[ind + 1][1][limit]);
//                 dp[ind][0][limit] = max(arr[ind] + dp[ind + 1][1][limit - 1],
//                                         dp[ind + 1][0][limit]);
//             }
//         }

//         return dp[0][1][k];
//     }

// <========SPACE OPTIMATION==========>

  int maxProfit(int k , vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
      
        vector<int> nextBuy(k + 1, 0), nextNotBuy(k + 1, 0);
        vector<int> currBuy(k + 1, 0), currNotBuy(k + 1, 0);

        for (int ind = n - 1; ind >= 0; --ind) {
            
            currBuy[0] = 0;
            currNotBuy[0] = 0;

            for (int limit = 1; limit <= k; ++limit) {
                currBuy[limit] = max(-arr[ind] + nextNotBuy[limit],
                                      nextBuy[limit]);
                currNotBuy[limit] = max(arr[ind] + nextBuy[limit - 1],
                                         nextNotBuy[limit]);
            }

            
            swap(nextBuy, currBuy);
            swap(nextNotBuy, currNotBuy);
        }

        return nextBuy[k]; 
    }
};