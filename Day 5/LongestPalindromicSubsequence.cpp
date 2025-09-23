#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
 
//<========MEMORIZATION========>
//   int solve(string &s, int i, int j, vector<vector<int>>& dp) {
//         // Base cases
//         if (i > j) return 0;         
//         if (i == j) return 1;        
        
//         if (dp[i][j] != -1) return dp[i][j];
        
//         if (s[i] == s[j]) {
//          
//             return dp[i][j] = 2 + solve(s, i + 1, j - 1, dp);
//         } else {
//
//             return dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
//         }
//     }
    
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return solve(s, 0, n - 1, dp);
//     }

//<========TABULATION========>
    int solve(string t1,string t2){
   vector<vector<int>>dp(t1.size()+1,vector<int>(t2.size()+1,0));

    for(int i=t1.length()-1;i>=0;i--){
        for(int j=t2.length()-1;j>=0;j--){
            int ans=0;

            if(t1[i]==t2[j])
            ans=1+dp[i+1][j+1];

            else 
            ans=max(dp[i+1][j],dp[i][j+1]);

            dp[i][j]=ans;
        }
    }
    return dp[0][0];
} 
 
    int longestPalinSubseq(string s) {
        string str=s;
        reverse(s.begin(),s.end());

        return solve(s,str);
    }
};