#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // <=========RECURSIVE===========>

    // bool check(const vector<int>&a, const vector<int>&b){
    //     return a[0]<=b[0] && a[1]<=b[1] && a[2]<=b[2];
    // }

    // int solve(int currInd, int prevInd , vector<vector<int>>&cuboids,int n){
    //     if(currInd>=n)
    //     return 0;

    //     int include=0;
    //     if(prevInd==-1 || check(cuboids[prevInd],cuboids[currInd]))
    //     include=cuboids[currInd][2]+solve(currInd+1,currInd,cuboids,n);

    //     int exclude=solve(currInd+1,prevInd,cuboids,n);

    //     return max(include,exclude);


    // }

    // int maxHeight(vector<vector<int>>&cuboids){
    //     for(auto &c: cuboids){
    //         sort(c.begin(),c.end());
    //     }

    //     sort(cuboids.begin(),cuboids.end());
        
    //     return solve(0,-1,cuboids,cuboids.size());

    // }

    // bool checkCond(vector<int>& a, vector<int>& b) {
    //     return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
    // }

    // int solve(int currIdx, int prevIdx, vector<vector<int>>& cuboids, vector<vector<int>>& dp) {
    //     if (currIdx == cuboids.size()) 
    //     return 0; 

    //     if (dp[currIdx][prevIdx + 1] != -1) 
    //     return dp[currIdx][prevIdx + 1]; 


    //     int exclude = solve(currIdx + 1, prevIdx, cuboids, dp);

    //     int include = 0;
    //     if (prevIdx == -1 || checkCond(cuboids[prevIdx], cuboids[currIdx])) {
    //         include = cuboids[currIdx][2] + solve(currIdx + 1, currIdx, cuboids, dp);
    //     }

    //     return dp[currIdx][prevIdx + 1] = max(include, exclude);
    // }

    // int maxHeight(vector<vector<int>>& cuboids) {
    //     for (auto& c : cuboids) 
    //     sort(c.begin(), c.end());

    //     sort(cuboids.begin(), cuboids.end());

    //     int n = cuboids.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));

    //     return solve(0, -1, cuboids, dp);
    // 
    //}


    //<=============TABULATION============>

    bool checkCond(vector<int>& a, vector<int>& b) {
        return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
    }


    int maxHeight(vector<vector<int>>& cuboids) {
   
    for (auto& c : cuboids) 
    sort(c.begin(), c.end());
    
    sort(cuboids.begin(), cuboids.end());

    int n = cuboids.size();

    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int currIdx = n - 1; currIdx >= 0; currIdx--) {
        for (int prevIdx = -1; prevIdx < n; prevIdx++) {
            int exclude = dp[currIdx + 1][prevIdx + 1];

            int include = 0;
            if (prevIdx == -1 || checkCond(cuboids[prevIdx], cuboids[currIdx])) {
                include = cuboids[currIdx][2] + dp[currIdx + 1][currIdx + 1];
            }

            dp[currIdx][prevIdx + 1] = max(include, exclude);
        }
    }

    return dp[0][0]; 
}
};