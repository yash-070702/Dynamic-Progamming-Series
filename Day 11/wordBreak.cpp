#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.length();
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        vector<int> dp(n+1, false);
        dp[0] = true;  

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                string prefix = s.substr(j, i - j);
                if(dp[j] && st.find(prefix) != st.end()) {
                    dp[i] = true;
                    break; 
                }
            }
        }

        return dp[n];
    }