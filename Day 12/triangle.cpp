#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //<======RECURSION=======>

    // int solve(vector<vector<int>>&triangle,int n , int i, int j){
    //  if(i==n-1)
    //  return triangle[i][j];

    //  if(i>=n || j>=n)
    //  return INT_MAX;

    //  int curr=triangle[i][j]+solve(triangle,n,i+1,j);
    //  int next=triangle[i][j]+solve(triangle,n,i+1,j+1);

    //  return min(curr,next);
    // }
    

    // int minimumTotal(vector<vector<int>>& triangle) {

    //  if(triangle.size()==1)
    //  return triangle[0][0];

    //  int n=triangle.size();
   
    // return solve(triangle,triangle.size(),0,0);        
    // }

    //<========MEMORIZATION===========>
     
    // int solve(vector<vector<int>>& triangle,int size,int i ,int j,vector<vector<int>> &dp){
    //     if (i == size - 1) return triangle[i][j];

    //    if(dp[i][j]!=-1)
    //    return dp[i][j];
       
    //     int left=solve(triangle,size,i+1,j,dp)+triangle[i][j];
    //     int right=solve(triangle,size,i+1,j+1,dp)+triangle[i][j];
        
    //     dp[i][j]= min(left,right);
    //     return dp[i][j];
        
    // } 

    // int minimumTotal(vector<vector<int>>& triangle) {

    //  if(triangle.size()==1)
    //  return triangle[0][0];
    //  int n=triangle.size();
    // vector<vector<int>> dp(n, vector<int>(n, -1));
   
    //     int answer=solve(triangle,triangle.size(),0,0,dp);

    //     return answer;
        
    // }

    //<==========TABULATION===========>
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize last row
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Bottom-up calculation
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    return dp[0][0];
}
};