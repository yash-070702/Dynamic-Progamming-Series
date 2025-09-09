#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //<==========RECURSION===========>

    // int solve(int ind1 , int ind2 , string &str1 , string &str2){
    //     if(ind1<0)
    //     return ind2+1;

    //     if(ind2<0)
    //     return ind1+1;

    //     if(str1[ind1]==str2[ind2])
    //     return solve(ind1-1, ind2-1 , str1 , str2);

    //     int delete1=1+solve(ind1-1, ind2, str1, str2);
    //     int delete2=1+solve(ind1,ind2-1,str1,str2);

    //     return min(delete1,delete2);


    // }

    // int minDistance(string word1, string word2) {
    //     int m=word1.size();
    //     int n=word2.size();
        
    //     return solve(m-1,n-1,word1,word2);
    // }

    // <============MEMORIZATION============>

    // int solve( string &word1, string &word2 , int i , int j, vector<vector<int>>&dp) {
       
    //     if (i < 0) return j + 1; 
    //     if (j < 0) return i + 1; 
        
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
     
    //     if (word1[i] == word2[j])
    //         return dp[i][j]=solve(word1, word2, i - 1, j - 1,dp);

    
    //     int deleteFromWord1 = 1 + solve(word1, word2, i - 1, j,dp);
    //     int deleteFromWord2 = 1 + solve(word1, word2, i, j - 1,dp);

    //     return dp[i][j]=min(deleteFromWord1, deleteFromWord2);
    // }

    // int minDistance(string word1, string word2) {
    //     int m=word1.size();
    //     int n=word2.size();

    //     vector<vector<int>>dp(m,vector<int>(n,-1));
        
    //     return solve(m-1,n-1,word1,word2,dp);
    // }

    //<===========TABULATION===========>

     int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcs = dp[n][m];
        return (n - lcs) + (m - lcs);
    }

};
