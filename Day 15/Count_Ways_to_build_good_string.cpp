#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int MOD = 1e9 + 7;

    //<======RECURSION=======>

    // int solve(int length , int low ,int high , int zero , int one){
    //     if(length>high)
    //     return 0;

    //     if(length>=low && length<=high)
    //     {
    //         return 1+solve(length+zero,low,high,zero,one)%MOD +solve(length+one,low,high,zero,one)%MOD;
    //     }

    //     else{
    //         return solve(length+zero,low,high,zero,one)%MOD+solve(length+one,low,high,zero,one)%MOD;
    //     }
    // }
    
    // int countGoodStrings(int low, int high, int zero, int one) {
    //     return solve(0,low,high,zero,one);
    // }

    //<=======MEMORIZATION========>

    // int solve(int length , int low ,int high , int zero , int one, vector<int>& dp) {
    //     if (length > high)
    //         return 0;

    //     if (dp[length] != -1)
    //         return dp[length];

    //     if (length >= low && length <= high) {
    //         return dp[length] = (1 
    //             + solve(length + zero, low, high, zero, one, dp) % MOD 
    //             + solve(length + one, low, high, zero, one, dp) % MOD
    //         ) % MOD;
    //     } 
    //     else {
    //         return dp[length] = (
    //             solve(length + zero, low, high, zero, one, dp) % MOD 
    //             + solve(length + one, low, high, zero, one, dp) % MOD
    //         ) % MOD;
    //     }
    // }
    
    // int countGoodStrings(int low, int high, int zero, int one) {
    //     vector<int> dp(high + 1, -1);
    //     return solve(0, low, high, zero, one, dp);
    // }

    //<========TABULATION=========>

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);

        dp[0] = 1; 

        for (int length = 1; length <= high; length++) {
            long long ways = 0;

            if (length - zero >= 0)
                ways = (ways + dp[length - zero]) % MOD;

            if (length - one >= 0)
                ways = (ways + dp[length - one]) % MOD;

            dp[length] =ways;
        }

        long long ans = 0;
        for (int len = low; len <= high; len++) {
            ans = (ans + dp[len]) % MOD;
        }

        return ans;
    }
};