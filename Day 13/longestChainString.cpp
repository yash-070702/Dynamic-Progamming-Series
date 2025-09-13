#include<bits/stdc++.h>
using namespace std;

class Solution {
public:   

    bool isPredecessor(string s1, string s2){

        if(s1.size()+1!=s2.size())
        return false;
        
        bool skipped=false;

        int i=0,j=0;

        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                if(skipped)
                return false;

                skipped=true;
                j++;
            }
        }
return true;
    }

    //<========RECURSION=========>

    // int solve(int indx,int prev ,vector<string>&words, int n){
    //     if(indx>=n)
    //     return 0;

    //     int exclude=solve(indx+1,prev,words,n);

    //     int include=0;
    //     if(prev==-1 || isPredecessor(words[prev],words[indx]))
    //     include=1+solve(indx+1,indx,words,n);

    //     return max(exclude,include);
    // }
    
    // int longestStrChain(vector<string>& words) {
    //     int n=words.size();
    //         sort(words.begin(), words.end(), 
    //          [](string &a, string &b) { return a.size() < b.size(); });
    //     return solve(0,-1,words,n);
    // }

    //<========MEMORIZATION=========>

    // int solve(int indx,int prev ,vector<string>&words, int n,vector<vector<int>>&dp){
    //     if(indx>=n)
    //     return 0; 

    //     if(dp[indx][prev+1]!=-1)
    //     return dp[indx][prev+1];

    //     int exclude=solve(indx+1,prev,words,n,dp);

    //     int include=0;
    //     if(prev==-1 || isPredecessor(words[prev],words[indx]))
    //     include=1+solve(indx+1,indx,words,n,dp);

    //     return dp[indx][prev+1]=max(exclude,include);
    // }
    
    // int longestStrChain(vector<string>& words) {
    //     int n=words.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
    //         sort(words.begin(), words.end(), 
    //          [](string &a, string &b) { return a.size() < b.size(); });
    //     return solve(0,-1,words,n,dp);
    // }

    //<=======TABULATION=========>
    int longestStrChain(vector<string>& words) {
        int n = words.size();

       
        sort(words.begin(), words.end(), 
             [](string &a, string &b) { return a.size() < b.size(); });

        vector<int> dp(n, 1);  
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};