#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // static bool cmp(vector<int>&a,vector<int>&b){

    //     if(a[0]==b[0])
    //     return a[1]<b[1];


    //     return a[0]<b[0];
    // }

    // <------------RECURSION------------->

    // int solve(int curr , int prev , vector<vector<int>>& envelopes){
    //     if(curr==envelopes.size())
    //     return 0;

    //     int include=0;
    //     if(prev==-1 ||(envelopes[curr][0]>envelopes[prev][0]&&envelopes[curr][1]>envelopes[prev][1]))
    //     include=1+solve(curr+1,curr,envelopes);

    //     int exclude=solve(curr+1,prev,envelopes);

    //     return max(include,exclude);
    // }


    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     sort(envelopes.begin(),envelopes.end(),cmp);
    //     return solve(0,-1,envelopes);
    // }

    // <-------------MEMORISATION----------->

    //  int solve(int curr , int prev , vector<vector<int>>& envelopes,vector<vector<int>>&dp){
    //     if(curr==envelopes.size())
    //     return 0;

    //     if(dp[curr][prev+1]!=-1)
    //     return dp[curr][prev+1];

    //     int include=0;
    //     if(prev==-1 ||(envelopes[curr][0]>envelopes[prev][0]&&envelopes[curr][1]>envelopes[prev][1]))
    //     include=1+solve(curr+1,curr,envelopes,dp);

    //     int exclude=solve(curr+1,prev,envelopes,dp);

    //     return dp[curr][prev+1]=max(include,exclude);
    // }

    //  int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     int n=envelopes.size();
    //     sort(envelopes.begin(),envelopes.end(),cmp);
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     return solve(0,-1,envelopes,dp);
    // }

   //<-------------TABULATION----------->

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1]; 
        return a[0] < b[0]; 
    }

   int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

     
        vector<int> heights;
        for (auto &env : envelopes) heights.push_back(env[1]);

     
        vector<int> lis;
        for (int h : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) lis.push_back(h);
            else *it = h;
        }
        return lis.size();
    }

};