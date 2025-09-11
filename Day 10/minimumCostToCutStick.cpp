#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    //<===========RECURSION==========>
    
    // int solve(int start ,int end, vector<int>&cuts){
        
    //     if(end-start<=1)
    //     return 0;

    //     int ans=INT_MAX;

    //     for(int i=start+1;i<=end-1;i++){
    //         int cost=cuts[end]-cuts[start]+solve(start,i,cuts)+solve(i,end,cuts);
    //         ans=min(ans,cost);
    //     }        
    //     return ans;
    // }

    // int minCost(int n, vector<int>& cuts) {
    //     sort(cuts.begin(),cuts.end());
    //     cuts.insert(cuts.begin(),0);
    //     cuts.insert(cuts.end(),n);
    //     return solve(0,cuts.size()-1,cuts);

    // }

    //<=======MEMORIZATION=======>

    // int solve(int start ,int end, vector<int>&cuts,vector<vector<int>>&dp){
        
    //     if(end-start<=1)
    //     return 0;

    //     if(dp[start][end]!=-1)
    //     return dp[start][end];

    //     int ans=INT_MAX;

    //     for(int i=start+1;i<=end-1;i++){
    //         int cost=cuts[end]-cuts[start]+solve(start,i,cuts,dp)+solve(i,end,cuts,dp);
    //         ans=min(ans,cost);
    //     }        
    //     return dp[start][end]=ans;
    // }

    // int minCost(int n, vector<int>& cuts) {
    //     sort(cuts.begin(),cuts.end());
    //     cuts.insert(cuts.begin(),0);
    //     cuts.insert(cuts.end(),n);
    //     vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
    //     return solve(0,cuts.size()-1,cuts,dp);

    // }

    //<=======TABULATION=========>

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {
            for (int i = 0; i + len < m; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][m - 1];
    }
};