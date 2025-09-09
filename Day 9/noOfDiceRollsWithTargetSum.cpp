#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int MOD=1000000007;

    //<========RECURSION==========>


    // int solve(int dice, int faces , int target){
    // if(target<0)
    // return 0;

    // if(target==0 && dice==0)
    // return 1;

    // if(target==0 || dice==0)
    // return 0;

    // int ans=0;

    // for(int i=1;i<=faces;i++){
    // ans=1+solve(dice-1,faces,target-i);
    // }

    // return ans;
    // }

    // int numRollsToTarget(int dice, int faces, int target) {
    //     return solve(dice,faces,target);
    // }

    //<===========MEMORIZATION============>
   
    // long long solveMem(int dice ,int faces,int target,vector<vector<long long>>&dp){
    //     if(target<0)
    //     return 0;

    //     if(target==0 && dice!=0)
    //     return 0;

    //     if(target!=0 && dice==0)
    //     return 0;
        
    //     if(target==0 && dice==0)
    //     return 1;

    //     if(dp[dice][target]!=-1)
    //     return dp[dice][target];

    //     long long ans=0;
    //     for(int i=1;i<=faces;i++){
    //         ans=ans+solve(dice-1,faces,target-i,dp);
    //     }
    //     return dp[dice][target]=ans%MOD;
    // }

    // int numRollsToTarget(int dice, int faces, int target) {
    //     vector<vector<long long>>dp(dice+1,vector<long long>(target+1,-1));
    //     return solveTab(dice,faces,target,dp);
        
    // }
    

    //<===========TABULATION==============>

    int numRollsToTarget(int dice, int faces, int target) {
          vector<vector<int>>dp(dice+1,vector<int>(target+1,0));

        dp[0][0]=1;


        for(int i=1;i<=dice;i++){
            for(int j=1;j<=target;j++){
                 long long ans=0;
              for(int k=1;k<=faces;k++){
               if (j - k >= 0)
                ans=ans%MOD+dp[i-1][j-k]%MOD;
            }
             dp[i][j]=ans%MOD;
            }
           
        }
        return dp[dice][target];
        
    }
};