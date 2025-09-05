#include <bits/stdc++.h>   
using namespace std;
class Solution {
public:

// <=======RECURSIVE==========>
//    int countTrees(int n){
//     if(n==0||n==1)
//     return 1;
    
//        int ans=0;
//        for(int i=1;i<=n;i++){
//         ans+=countTrees(i-1)*countTrees(n-i);
//        }
//        return ans;
//    }

//     int numTrees(int n) {
//      return countTrees(n);
//     }

//<==========MEMORIZATION============>
//    int countTrees(int n, vector<int>&dp){
//     if(n==0||n==1)
//     return 1;

//     if(dp[n]!=-1)
//     return dp[n];
    
//        int ans=0;
//        for(int i=1;i<=n;i++){
//         ans+=countTrees(i-1,dp)*countTrees(n-i,dp);
//        }

//        return dp[n]=ans;

//    }

//     int numTrees(int n) {
//       vector<int>dp(n+1,-1);
     
//      return countTrees(n,dp);

  
//     }

//<=========TABULATION==========>

int numTrees(int n){
    vector<int>dp(n+1,0);

    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
        dp[i]+=dp[j-1]*dp[i-j];
        }
    }

    return dp[n];
}
};