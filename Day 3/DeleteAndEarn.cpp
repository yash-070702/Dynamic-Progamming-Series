#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
//<---------------------- USING MEMORIZATION-------------------->


    // int solve(int n,vector<int>&freq,vector<int>&dp){
    //     if(n==0)
    //     return 0;

    //     if(n==1)
    //     return freq[1];

    //     if(dp[n]!=-1)
    //     return dp[n];

    //     int inc=n*freq[n]+solve(n-2,freq,dp);
    //     int exc=solve(n-1,freq,dp);

    //     return dp[n]=max(inc,exc);

    // }

    // int deleteAndEarn(vector<int>&nums){
    //     int maxVal=*max_element(nums.begin(),nums.end());
    //     vector<int>freq(maxVal+1,0);

    //     for(int &num:nums){
    //     freq[num]++;
    //     }
    //     vector<int>dp(maxVal+1,-1);
    //     return solve(maxVal,freq,dp);
    // }

    //<------------------USING TABULATION------------------>

    // int deleteAndEarn(vector<int>&nums){
    //     int maxVal=*max_element(nums.begin(),nums.end());
    //     vector<int>freq(maxVal+1,0);

    //     for(int &num:nums){
    //     freq[num]++;
    //     }
    //      vector<int>dp(maxVal+1,-1);

    //     dp[0]=0;
    //     dp[1]=freq[1];

    //     for(int i=2;i<=maxVal;i++){
    //         int inc=i*freq[i]+dp[i-2];
    //         int exc=dp[i-1];
    //         dp[i]=max(inc,exc);
    //     }
        
    //     return dp[maxVal];
    // }

     // <--------------- USING SPACE OPTIMIZATION------------------->
        int deleteAndEarn(vector<int>&nums){
        int maxVal=*max_element(nums.begin(),nums.end());
        vector<int>freq(maxVal+1,0);

        for(int &num:nums){
        freq[num]++;
        }

        int prev=0;
        int curr=freq[1];

        for(int i=2;i<=maxVal;i++){
            int inc=i*freq[i]+prev;
            int exc=curr;
            prev=curr;
            curr=max(inc,exc);

        }
        
        return curr;
    }
};
