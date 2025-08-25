#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

//<==============MEMORIZATION================>
// int solve(string t1,string t2, int i, int j, vector<vector<int>>&dp){

//     if(i==t1.size())
//     return t2.size()-j;  // it implies that string t1 is short 

//     if(j==t2.size())
//     return t1.size()-i;   //it means that string t2 is short
    
//     if(dp[i][j]!=-1)
//     return dp[i][j];
    
//     int ans=0;

//     if(t1[i]==t2[j])
//     return solve(t1,t2,i+1,j+1,dp);
         
//     else{
//         int insertAns=1+solve(t1,t2,i,j+1,dp);
//         int deleteAns=1+solve(t1,t2,i+1,j,dp);
//         int updateAns=1+solve(t1,t2,i+1,j+1,dp);

//         ans=min(insertAns,min(deleteAns,updateAns));

//     }
    
//     return dp[i][j]=ans;

// }
//     int minDistance(string word1, string word2) {
//         vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
//         return solve(word1,word2,0,0,dp);
//     }


//<==============TABULATION==============>
// int solve(int i , int j ,string word1,string word2,vector<vector<int>>&dp){
//     if(i < 0) return j + 1;
//     if(j < 0) return i + 1;

//     if(dp[i][j]!=-1)
//     return dp[i][j];

//     if(word1[i]==word2[j])
//     return dp[i][j]=solve(i-1,j-1,word1,word2,dp);

//     int upt=1+solve(i-1,j-1,word1,word2,dp);
//     int del=1+solve(i-1,j,word1,word2,dp);
//     int ins=1+solve(i,j-1,word1,word2,dp);

//     return dp[i][j]= min(upt,min(del,ins));

// }


// int minDistance(string word1,string word2){
//     int i=word1.length();
//     int j=word2.length();
//     vector<vector<int>>dp(i,vector<int>(j,-1));
//     return solve(i-1,j-1,word1,word2,dp);
//}

//<===========SPACE OPTIMIZATION============>

 int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        // Base case: converting "" to word2
        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i; // converting word1[0..i-1] to ""
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] == word2[j-1]) {
                    curr[j] = prev[j-1];
                } else {
                    curr[j] = 1 + min({prev[j],    // delete
                                       curr[j-1],  // insert
                                       prev[j-1]}); // replace
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};