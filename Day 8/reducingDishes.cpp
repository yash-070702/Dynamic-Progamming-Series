#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

//<=========RECURSION=========>

// int solve(vector<int>&satisfaction,int &n ,int index,int time){
//     if(index==n)
//     return 0;

//     int exclude=solve(satisfaction,n,index+1,time);
//     int include=satisfaction[index]*(time+1) + solve(satisfaction,n,index+1,time+1);

//     return max(include,exclude);
   
// }

// int maxSatisfaction(vector<int>& satisfaction) {
//         int n=satisfaction.size();
//         sort(satisfaction.begin(),satisfaction.end());
//         return solve(satisfaction,n,0,0);
// }

//<===========MEMORIZATION==========>

// int solve(vector<int>&satisfaction,int &n ,int index,int time,vector<vector<int>>&dp){
//     if(index==n)
//     return 0;

//     if(dp[index][time]!=-1)
//     return dp[index][time];

//     int exclude=solve(satisfaction,n,index+1,time,dp);
//     int include=satisfaction[index]*(time+1) + solve(satisfaction,n,index+1,time+1,dp);

//     dp[index][time]=max(include,exclude);
//     return dp[index][time];

// }
//     int maxSatisfaction(vector<int>& satisfaction) {
//         int n=satisfaction.size();
//         sort(satisfaction.begin(),satisfaction.end());
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

//         return solve(satisfaction,n,0,0,dp);
//     }
    
//<==========TABULATION===========>


//     int maxSatisfaction(vector<int>& satisfaction) {
//         int n=satisfaction.size();
//         sort(satisfaction.begin(),satisfaction.end());
//         vector<vector<int>>dp(n+1,vector<int>(n+1,0));

//     for(int index=n-1;index>=0;index--){
//         for(int time=index;time>=0;time--){
//           int exclude=dp[index+1][time];
//           int include=satisfaction[index]*(time+1) +dp[index+1][time+1];
          
//           dp[index][time]=max(include,exclude);

//         }
//     }
// return dp[0][0];
//     }

//<========SPACE OPTIMIZATION=========>


    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<int>next(n+1,0);
        vector<int>curr(n+1,0);

    for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
          int exclude=next[time];
          int include=satisfaction[index]*(time+1) +next[time+1];
          
          curr[time]=max(include,exclude);

        }
        next=curr;
    }
return next[0];
    }

};