#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //<=========RECURSION==========> 

    // int solve(string &s , int ind , bool isOneArea){
    //     if(ind==s.size())
    //     return 0;

    //     int numOf0=INT_MAX;
    //     int numOf1=INT_MAX;

    //     if(!isOneArea){
    //         if(s[ind]=='0')
    //         numOf0=solve(s,ind+1,false);

    //         else
    //         numOf0=1+solve(s,ind+1,false);
    //     }


    //         if(s[ind]=='1')
    //         numOf1=solve(s,ind+1,true);

    //         else
    //         numOf1=1+solve(s,ind+1,true);

    //     return min(numOf0,numOf1);
    // }

    // int minFlipsMonoIncr(string s) {
    //     return solve(s,0,false);
    // }

    //<========MEMORIZATION=========>

    // int solve(string &s , int ind , bool isOneArea,vector<vector<int>>&dp){
    //     if(ind==s.size())
    //     return 0;

    //     int numOf0=INT_MAX;
    //     int numOf1=INT_MAX;

    //     if(dp[ind][isOneArea]!=-1)
    //     return dp[ind][isOneArea];


    //     if(!isOneArea){
    //         if(s[ind]=='0')
    //         numOf0=solve(s,ind+1,false,dp);

    //         else
    //         numOf0=1+solve(s,ind+1,false,dp);
    //     }


    //         if(s[ind]=='1')
    //         numOf1=solve(s,ind+1,true,dp);

    //         else
    //         numOf1=1+solve(s,ind+1,true,dp);

    //     return dp[ind][isOneArea]=min(numOf0,numOf1);
    // }

    // int minFlipsMonoIncr(string s) {
    //     vector<vector<int>>dp(s.size()+1,vector<int>(2,-1));
    //     return solve(s,0,false,dp);
    // }

    //<========TABULATION==========>
    int minFlipsMonoIncr(string s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int isOneArea = 0; isOneArea <= 1; isOneArea++) {
            int numOf0 = INT_MAX;
            int numOf1 = INT_MAX;

           
            if (!isOneArea) {
                if (s[ind] == '0')
                    numOf0 = dp[ind + 1][0];
                else
                    numOf0 = 1 + dp[ind + 1][0];
            }

           
            if (s[ind] == '1')
                numOf1 = dp[ind + 1][1];
            else
                numOf1 = 1 + dp[ind + 1][1];

            dp[ind][isOneArea] = min(numOf0, numOf1);
        }  
    }

    return dp[0][0]; 
}
};