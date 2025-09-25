#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //<======RECURSION=======>

    // int solve(int i , int M , vector<int>&piles,int &n){
    // if(i>=n)
    // return 0;

    // int total=0;

    // for(int j=i;j<n;j++)
    // total+=piles[j];

    // int maxStones=0;
    // int take=0;

    // for(int X=1;X<=2*M && X+i-1<n;X++){
    // take+=piles[X+i-1];
    // int oppo=solve(i+X,max(M,X),piles,n);
    // maxStones=max(maxStones,total-oppo);
    // }
    // return maxStones;
    // }

    // int stoneGameII(vector<int>& piles) {
    //     int n=piles.size();
    //     return solve(0,1,piles,n,dp);
    // }

    //<=====MEMORIZATION=======>

    int solve(int i , int M , vector<int>&piles,int &n,vector<vector<int>>&dp){
    if(i>=n)
    return 0;

    if(dp[i][M]!=-1)
    return dp[i][M];

    int total=0;

    for(int j=i;j<n;j++)
    total+=piles[j];

    int maxStones=0;
    int take=0;

    for(int X=1;X<=2*M && X+i-1<n;X++){
    take+=piles[X+i-1];
    int oppo=solve(i+X,max(M,X),piles,n,dp);
    maxStones=max(maxStones,total-oppo);
    }
    return dp[i][M]=maxStones;
    }

    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,1,piles,n,dp);
    }


    //<=======TABULATION========>

//     int solve(int i, int M, vector<int>& piles) {
// 	int n = piles.size();
// 	if (i >= n) return 0;

// 	int total = 0;
// 	for (int k = i; k < n; k++) 
// 		total += piles[k];

// 	int maxStones = 0, take = 0;

// 	for (int X = 1; X <= 2 * M && i + X - 1 < n; X++) {
// 		take += piles[i + X - 1];
// 		int opponent = solve(i + X, max(M, X), piles);
// 		maxStones = max(maxStones, total - opponent);
// 	}
// 	return maxStones;
// }

// int stoneGameII(vector<int>& piles) {
// 	return solve(0, 1, piles);
// }
};