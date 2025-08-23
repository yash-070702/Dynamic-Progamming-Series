#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // <------------------MEMORIZATION------------------->
    // int solve(int capacity,vector<int>&val,vector<int>&wt,int index, vector<vector<int>>&dp){
    //    if(index==0){
    //        if(wt[0]<=capacity){
    //            capacity-=wt[0];
    //            return val[0];
    //        }
    //        else
    //        return 0;
    //    }
           
    //        if(dp[index][capacity]!=-1)
    //        return dp[index][capacity];
           
    //        int include=INT_MIN;
           
    //        if(wt[index]<=capacity)
    //        include=val[index]+solve(capacity-wt[index],val,wt,index-1,dp);
           
    //        int exclude=solve(capacity,val,wt,index-1,dp);
           
    //   return dp[index][capacity]=max(include,exclude);
    // }
  
    // int knapsack(int W, vector<int> &val, vector<int> &wt) {
    
    // int n=val.size();
    // vector<vector<int>>dp(n,vector<int>(W+1,-1));
    
    // return solve(W,val,wt,n-1,dp);
        
    // }


     //<------------------TABULATION------------------->
    
   int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    if (n == 0 || W == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(W+1, 0));

  
    for (int i = 0; i <= W; i++) {
        if (wt[0] <= i)
            dp[0][i] = val[0];
        else
            dp[0][i] = 0;
    }

   
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int include = 0;
            if (wt[i] <= w)
                include = val[i] + dp[i-1][w-wt[i]];
            
            int exclude = dp[i-1][w];
            dp[i][w] = max(include, exclude);
        }
    }

    return dp[n-1][W];
}



};