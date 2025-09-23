#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int n;
    const int MOD=1e9 + 7;
 
    //<======RECURSION========>

    // int solve(int start,string &s, int k ){
    //     if(start>=n)
    //     return 1;

    //     if(s[start]=='0')
    //     return 0;

    //     int ans=0;
    //     int num=0;
    //     for(int end=start;end<n;end++){
    //     num=(num*10)+(s[end]-'0');

    //     if(num>k)
    //     break;

    //     ans=ans+solve(end+1,s,k);
    //     }
    //     return ans;
    // }

    // int numberOfArrays(string s, int k) {
    //     n=s.size();
    //     return solve(0,s,k);
    // }

    //<======MEMORIZATION========>

    //  int solve(int start,string &s, int k ,vector<int>&dp ){
    //     if(start>=n)
    //     return 1;

    //     if(s[start]=='0')
    //     return 0;

    //     if(dp[start]!=-1)
    //     return dp[start];

    //     long long ans=0;
    //     long long num=0;
    //     for(int end=start;end<n;end++){
    //     num=(num*10)+(s[end]-'0');

    //     if(num>k)
    //     break;

    //     ans = (ans + solve(end+1, s, k, dp)) % MOD;

    //     }
    //     return dp[start]=ans;
    // }

    // int numberOfArrays(string s, int k) {
    //     n=s.size();
    //     vector<int>dp(n+1,-1);
    //     return (solve(0,s,k,dp))%MOD;
    // }

    //<====TABULATION=====>

    int numberOfArrays(string s, int k) {
    int n = s.size();
    vector<long long> dp(n + 1, 0);
    dp[n] = 1;
    for (int start = n - 1; start >= 0; start--) {
        if (s[start] == '0') { 
            dp[start] = 0;
            continue;
        }

        long long num = 0;
        for (int end = start; end < n; end++) {
            num = num * 10 + (s[end] - '0');
            if (num > k) break; 

            dp[start] = (dp[start] + dp[end + 1]) % MOD;
        }
    }

    return dp[0];
}

};