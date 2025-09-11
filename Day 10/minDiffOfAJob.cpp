#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    //<======RECURSION=======>

    // int solve(int index, int days , int n , vector<int>&job){
    //     if(days==1)
    //     return *max_element(job.begin()+index,job.end());

    //     int ans=INT_MAX;
    //     int curr=0;

    //     for(int i=index;i<=n-days;i++){
    //         curr=max(curr,job[i]);

    //         int next=solve(i+1,days-1,n,job);
    //         ans=min(ans,next+curr);
    //     }

    //     return ans;
    // }

    // int minDifficulty(vector<int>& jobDifficulty, int d) {
    //     int n=jobDifficulty.size();

    //     if(n<d)
    //     return -1;

    //     return solve(0,d,n,jobDifficulty);
    // }

    //<=======MEMORIZATION========>

    // int solve(int index, int days , int n , vector<int>&job,vector<vector<int>>&dp){
    //     if(days==1)
    //     return *max_element(job.begin()+index,job.end());

    //     int ans=INT_MAX;
    //     int curr=0;

    //     if(dp[index][days]!=-1)
    //     return dp[index][days];

    //     for(int i=index;i<=n-days;i++){
    //         curr=max(curr,job[i]);

    //         int next=solve(i+1,days-1,n,job,dp);
    //         ans=min(ans,next+curr);
    //     }

    //     return dp[index][days]=ans;
    // }

    // int minDifficulty(vector<int>& jobDifficulty, int d) {
    //     int n=jobDifficulty.size();

    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

    //     if(n<d)
    //     return -1;

    //     return solve(0,d,n,jobDifficulty,dp);
    // }

    //<========TABULATION=========>

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1; 
        const int INF = 1e9;
        vector<vector<int>> dp(d + 1, vector<int>(n + 1, INF));

        dp[0][0] = 0; 

        for (int day = 1; day <= d; day++) {
            for (int i = day; i <= n; i++) { 
                int currMax = 0;
            
                for (int j = i; j >= day; j--) {
                    currMax = max(currMax, jobDifficulty[j - 1]); 
                    dp[day][i] = min(dp[day][i], dp[day - 1][j - 1] + currMax);
                }
            }
        }

        return dp[d][n];
    }
};