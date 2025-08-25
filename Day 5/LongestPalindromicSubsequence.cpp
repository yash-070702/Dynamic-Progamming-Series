#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
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