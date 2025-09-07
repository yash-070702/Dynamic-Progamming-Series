#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

   //<===========MEMORIZATION=============>
  

    bool solve(vector<int>& stones, int n, int currInd, int prevJump,vector<vector<int>>&dp,unordered_map<int,int>&mp) {
        if (currInd == n - 1) return true;

        // Memoization check
        if (dp[currInd][prevJump] != 0) 
            return dp[currInd][prevJump] ==2;

        for (int jump = prevJump - 1; jump <= prevJump + 1; jump++) {
            if (jump > 0) {
                int nextPos = stones[currInd] + jump;
                if (mp.find(nextPos) != mp.end()) {
                    int nextInd = mp[nextPos];
                    if (solve(stones, n, nextInd, jump,dp,mp)) {
                        dp[currInd][prevJump] =2; 
                        return true;
                    }
                }
            }
        }

        dp[currInd][prevJump] = 1; 
        return false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;

            int n = stones.size();

           vector<vector<int>> dp(n,vector<int>(n+1,false));
           unordered_map<int, int> mp;  

        for (int i = 0; i < n; ++i) {
            mp[stones[i]] = i;
        }

        return solve(stones, n, 0, 0,dp, mp);
    }

    //<==============RECURSIVE==============>

    // bool solve(vector<int>&stones,map<int,int>&mp , int ind , int k,int n){
    //     if(ind==n-1)
    //     return true;

    //     bool prev=false;
    //     if (k > 1 && mp.find(stones[ind] + k - 1) != mp.end())
    //     prev=solve(stones,mp,mp[stones[ind]+k-1],k-1,n);

    //     bool curr=false;
    //     if(mp.find(stones[ind]+k)!=mp.end())
    //     curr=solve(stones,mp,mp[stones[ind]+k],k,n);

    //     bool next=false;
    //     if(mp.find(stones[ind]+k+1)!=mp.end())
    //     next=solve(stones,mp,mp[stones[ind]+k+1],k+1,n);

    //     return prev||curr||next;

    // }

    // bool canCross(vector<int>&stones){
    //      int n=stones.size();
    //      if (n == 0)
    //       return true;

    //      if (n == 1)
    //       return true;

    //      if(stones[1]!=1)
    //      return false;

    //     map<int,int>mp;

    //     for(int i=0;i<n;i++){
    //         mp[stones[i]]=i;
    //     }

    //     return solve(stones,mp,1,1,n);
    // }


};
