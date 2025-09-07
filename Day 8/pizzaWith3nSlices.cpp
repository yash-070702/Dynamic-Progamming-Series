#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//<========RECURSIVE=========>

// int solve(vector<int>&slices,int end,int n,int curr){
// if(n==0 || curr>end)
// return 0;


// int include=slices[curr]+solve(slices,end,n-1,curr+2);
// int exclude=solve(slices,end,n,curr+1);

// return max(include,exclude);
// }
//     int maxSizeSlices(vector<int>& slices) {
//     int k=slices.size();

//     int case1=solve(slices,k-2,k/3,0);
//     int case2=solve(slices,k-1,k/3,1);

//     return max(case1,case2);
        
//     }

//<==========MEMORIZATION===========>    

// int solve(vector<int>&slices,int end,int n,int curr,vector<vector<int>>&dp){
// if(n==0 || curr>end )
// return 0;

// if(dp[n][curr]!=-1)
// return dp[n][curr];

// int include=slices[curr]+solve(slices,end,n-1,curr+2,dp);
// int exclude=solve(slices,end,n,curr+1,dp);

// return dp[n][curr]=max(include,exclude);
// }
//     int maxSizeSlices(vector<int>& slices) {
//     int k=slices.size();
//     vector<vector<int>>dp1(k+1,vector<int>(k+1,-1));
//     vector<vector<int>>dp2(k+1,vector<int>(k+1,-1));

//     int case1=solve(slices,k-2,k/3,0,dp1);
//     int case2=solve(slices,k-1,k/3,1,dp2);

//     return max(case1,case2);
        
//     }

//<===========TABULATION==============>

 int maxSizeSlices(vector<int>& slices) {
    int k=slices.size();
    vector<vector<int>>dp1(k+1,vector<int>(k+1,0));
    vector<vector<int>>dp2(k+2,vector<int>(k+2,0));

    for(int i=k-2;i>=0;i--){
        for(int n=1;n<=k/3;n++){
            int take=slices[i]+dp1[i+2][n-1];
            int leave=dp1[i+1][n];
            dp1[i][n]=max(take,leave);
        }
    }

    int case1=dp1[0][k/3];

    
    for(int i=k-1;i>0;i--){
        for(int n=1;n<=k/3;n++){
            int take=slices[i]+dp2[i+2][n-1];
            int leave=dp2[i+1][n];
            dp2[i][n]=max(take,leave);
        }
    }

    int case2=dp2[1][k/3];

    return max(case1,case2);
        
    }

};