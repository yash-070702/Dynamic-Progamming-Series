#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int solve(int &n , vector<int>&days, vector<int>&costs ,int idx, vector<int>&dp){
        if(idx>=n)
        return 0;

        if(dp[idx]!=-1)
        return dp[idx];

        int opt1=costs[0]+solve(n,days,costs,idx+1,dp);
        int i;

        for(i=idx;i<n&&days[i]<days[idx]+7;i++);

        int opt2=costs[1]+solve(n,days,costs,i,dp);

        for(i=idx;i<n&&days[i]<days[idx]+30;i++);

         int opt3 = costs[2]+solve(n,days,costs,i,dp);

         dp[idx]=min(opt1,min(opt2,opt3));
         return dp[idx];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);

        return solve(n,days,costs,0,dp);
    }
};