#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
// approach 
//  we start from end and when we find both elements same we will move both pointer to left 
//  if we find ? on string s then replace it with the curr element of string p 
//  if we find * we can either put nothing their or we can replace * with *and curr element of p 


  //<==========RECURSION==========>
    
    // bool solve(int i , int j , string &txt , string &pat){
    //     if(i<0 && j<0)
    //     return true;
        
    //     if(i>=0 && j<0)
    //     return false;
        
    //     if(i<0 && j>=0){
    //         for(int i=j;i>=0;i--){
    //             if(pat[i]!='?')
    //             return false;
    //         }
    //     return true;
    //     }
        
    //     if(txt[i]==pat[j] || pat[j]=='?')
    //     return solve(i-1,j-1,txt,pat);
        
    //     else if(pat[j]=='*')
    //     return solve(i-1,j,txt,pat)||solve(i,j-1,txt,pat);
        
    // }
    
    // bool isMatch(string &txt, string &pat) {
    //   int n=txt.size();
    //   int m=pat.size();
      
    //   return solve(n-1,m-1,txt,pat);
        
    // }
    
    
    //<==========MEMORIZATION=============>
    
    // bool solve(string &str, string &pattern , int i ,int j , vector<vector<int>>&dp){
    //     if(i<0 && j<0)
    //     return true;

    //     if(i>=0 && j<0)
    //     return false;

    //     if(i<0 && j>=0)
    //     {
    //         for(int k=0;k<=j;k++){
    //             if(pattern[k]!='*')
    //             return false;
    //         }
    //         return true;
    //     }

    //     if(dp[i][j]!=-1)
    //     return dp[i][j];

    //     if(str[i]==pattern[j] || pattern[j]=='?')
    //     return dp[i][j]=solve(str,pattern,i-1,j-1,dp);

    //     else if(pattern[j]=='*')
    //     return dp[i][j]=(solve(str,pattern,i-1,j,dp) || solve(str,pattern,i,j-1,dp));

    //     else return false;
    // }
    
    // bool isMatch(string s, string p) {

    //     vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));

    //     return solve(s,p,s.size()-1,p.size()-1,dp);
        
    // }

    //<==========TABULATION============>

   bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;

    for (int j = 1; j <= m; j++) {
        bool allStars = true;
        for (int k = 0; k < j; k++) {
            if (p[k] != '*') {
                allStars = false;
                break;
            }
        }
        dp[0][j] = allStars;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}
};