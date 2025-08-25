#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 
 //<-------------RECURSION---------------->

//  int solve(string &s1,string &s2 , int i , int j){
//         if(i==s1.size() || j==s2.size())
//         return 0;
        
//         if(s1[i]==s2[j])
//         return 1+solve(s1,s2,i+1,j+1);
    
//         return max(solve(s1,s2,i,j+1),solve(s1,s2,i+1,j));
//     }
//     int longestCommonSubsequence(string &s1, string &s2) {
//         return solve(s1,s2,0,0);
//     }


 //<------------MEMORIZATION-------------->

//  int solve(string &s1,string &s2 , int i , int j,vector<vector<int>>&dp){
//         if(i==s1.size() || j==s2.size())
//         return 0;
        
//         if(dp[i][j]!=-1)
//         return dp[i][j];
        
//         if(s1[i]==s2[j])
//         return dp[i][j] = 1+solve(s1,s2,i+1,j+1,dp);
    
//         return dp[i][j] = max(solve(s1,s2,i,j+1,dp),solve(s1,s2,i+1,j,dp));
//     }
//     int longestCommonSubsequence(string &s1, string &s2) {
//         int n1=s1.size();
//         int n2=s2.size();
//         vector<vector<int>>dp(n1,vector<int>(n2,-1));
//         return solve(s1,s2,0,0,dp);
//     }
 
//using tabulation
// int solve(string t1,string t2){
//     vector<vector<int>>dp(t1.size()+1,vector<int>(t2.size()+1,0));

//     for(int i=t1.length()-1;i>=0;i--){
//         for(int j=t2.length()-1;j>=0;j--){
//             int ans=0;

//             if(t1[i]==t2[j])
//             ans=1+dp[i+1][j+1];

//             else 
//             ans=max(dp[i+1][j],dp[i][j+1]);

//             dp[i][j]=ans;
//         }
//     }
//     return dp[0][0];
// } 

 //<---------------TABULATION------------->

// int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size(), m = text2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 if(text1[i-1] == text2[j-1]) {
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 } else {
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }

//         return dp[n][m]; 
//     }

//<---------------SPACE OPTIMIZATION------------>
int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        // Always iterate on the smaller string to save space
        if (m > n) swap(text1, text2), swap(n, m);

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr; // move current row into prev
        }

        return prev[m];
    }
 
};              
