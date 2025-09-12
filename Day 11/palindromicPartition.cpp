#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    
    bool isPalindrome(const string &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false; 
        }
        left++;
        right--;
    }
    return true; 
    }
    
    //<======RECURSIVE=======>
    
    // int solve(string s){
    //     if(s.length()==0)
    //     return 0;
        
    //     if(isPalindrome(s))
    //     return 0;
        
    //     int ans=INT_MAX;
        
    //     for(int i=1;i<=s.length();i++){
    //       if(isPalindrome(s.substr(0,i)))
    //       ans=min(ans,1+solve(s.substr(i)));
    //     }
        
    //     return ans;
    // }
     
    // int palPartition(string &s) {
    // return solve(s);
    // }
    
    //<=====MEMORIZATION=====>
    
    //  int solve(string s,unordered_map<string,int>&mp){
    //     if(s.length()==0)
    //     return 0;
        
    //     if(isPalindrome(s))
    //     return 0;
        
    //     if(mp.find(s)!=mp.end())
    //     return mp[s];
        
    //     int ans=INT_MAX;
        
    //     for(int i=1;i<=s.length();i++){
    //       if(isPalindrome(s.substr(0,i)))
    //       ans=min(ans,1+solve(s.substr(i),mp));
    //     }
        
    //     return mp[s]=ans;
    // }
     
    // int palPartition(string &s) {
    // unordered_map<string,int>mp;    
    // return solve(s,mp);
    // }
    
    //<====TABULATION====>
    
    int palPartition(string &s) {
        int n = s.length();
        vector<int> dp(n+1, 0);

        dp[n] = 0; // empty string requires 0 cuts

        // bottom-up build
        for (int i = n-1; i >= 0; i--) {
            string curr = s.substr(i);  
            if (isPalindrome(curr)) {
                dp[i] = 0;
                continue;
            }

            int ans = INT_MAX;
            for (int len = 1; len <= n - i; len++) {
                string prefix = s.substr(i, len);
                if (isPalindrome(prefix)) {
                    ans = min(ans, 1 + dp[i + len]);
                }
            }
            dp[i] = ans;
        }

        return dp[0];
    }
    
    
};