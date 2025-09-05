#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //<==========RECURSION===========>

    // int solve(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right){
    //     if(left==right)
    //     return 0;

    //     int ans=INT_MAX;

    //     for(int i=left;i<right;i++){
    //         ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}]+solve(arr,maxi,left,i)+solve(arr,maxi,i+1,right));
    //     }
    //     return ans;
    // }
   
    // int mctFromLeafValues(vector<int>& arr) {
    //     map<pair<int,int>,int>maxi;

    //     for(int i=0;i<arr.size();i++){
    //         maxi[{i,i}]=arr[i];

    //         for(int j=i+1;j<arr.size();j++){
    //             maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
    //         }
    //     }
    //     return solve(arr,maxi,0,arr.size()-1);
    // }

    //<=============MEMORISATION==============>

    // int solve(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right,vector<vector<int>>&dp){
    //     if(left==right)
    //     return 0;

    //     if(dp[left][right]!=-1)
    //     return dp[left][right];

    //     int ans=INT_MAX;

    //     for(int i=left;i<right;i++){
    //         ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}]+solve(arr,maxi,left,i,dp)+solve(arr,maxi,i+1,right,dp));
    //     }
    //     return dp[left][right]=ans;
    // }
   
    // int mctFromLeafValues(vector<int>& arr) {
    //     map<pair<int,int>,int>maxi;
    //     vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));

    //     for(int i=0;i<arr.size();i++){
    //         maxi[{i,i}]=arr[i];

    //         for(int j=i+1;j<arr.size();j++){
    //             maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
    //         }
    //     }
    //     return solve(arr,maxi,0,arr.size()-1,dp);
    // }

    //<=========TABULATION============>

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        vector<vector<int>> maxi(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            maxi[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                maxi[i][j] = max(maxi[i][j-1], arr[j]);
            }
        }

        
        const int INF = INT_MAX / 4;
        vector<vector<int>> dp(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) dp[i][i] = 0;

      
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                
                for (int k = i; k < j; ++k) {
                    int cost = dp[i][k] + dp[k+1][j] + maxi[i][k] * maxi[k+1][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][n-1];
    }
}; 