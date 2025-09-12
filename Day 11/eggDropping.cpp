#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    //<=========RECURSION=========>
    
    // int solve(int n , int k ){
    //     if(k==1 || k==0 || n==1)
    //     return k;
        
    //     int ans=INT_MAX;
        
    //     for(int i=1;i<=k;i++){
    //         int notBreak=solve(n,k-i);
    //         int willBreak=solve(n-1,i-1);
    //         ans=min(ans,1+max(notBreak,willBreak));
    //     }
        
    //     return ans;
    // }
    // int eggDrop(int n, int k) {
    // return solve(n,k);
        
    // }
    
    //<===========MEMORIZATION===========>
    
    int solve(int n , int k ,vector<vector<int>>&dp){
        if(k==1 || k==0 || n==1)
        return k;
        
        if(dp[n][k]!=-1)
        return dp[n][k];
        
        int ans = INT_MAX;
        int low = 1, high = k;

        while (low <= high) {
            int mid = (low + high) / 2;

            int willBreak = solve(n - 1, mid - 1, dp);   
            int notBreak = solve(n, k - mid, dp);   

            int worst = 1 + max(willBreak, notBreak);
            ans = min(ans, worst);

          
            if (willBreak > notBreak) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return dp[n][k] = ans;
    }
    int eggDrop(int n, int k) {
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return solve(n,k,dp);
         }
         
    //<=========TABULATION==========>
    //  int eggDrop(int n, int k) {
    //     vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        
    //     for (int i = 1; i <= n; i++) {
    //         dp[i][0] = 0;
    //         dp[i][1] = 1;
    //     }
        
     
    //     for (int j = 1; j <= k; j++) {
    //         dp[1][j] = j;
    //     }
        
       
    //     for (int i = 2; i <= n; i++) {
    //         for (int j = 2; j <= k; j++) {
    //             dp[i][j] = INT_MAX;
    //             for (int x = 1; x <= j; x++) {
    //                 int willBreak = dp[i-1][x-1]; 
    //                 int notBreak = dp[i][j-x];     
    //                 int worst = 1 + max(willBreak, notBreak);
    //                 dp[i][j] = min(dp[i][j], worst);
    //             }
    //         }
    //     }
        
    //     return dp[n][k];
    // }
};