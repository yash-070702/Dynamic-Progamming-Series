#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    //<======RECURSION======>
    
    // int solve(int ind,vector<vector<int>>&arr, int last){
    //     if(ind>=arr.size())
    //     return 0;
        
    //     int running=0;
    //     if(last!=0)
    //     running=arr[ind][0]+solve(ind+1,arr,0);
        
    //     int fighting=0;
    //     if(last!=1)
    //     fighting=arr[ind][1]+solve(ind+1,arr,1);
    
    //     int learning=0;
    //     if(last!=2)
    //     learning=arr[ind][2]+solve(ind+1,arr,2);
        
        
    //     return max(running,max(fighting,learning));
    // }
    
    
    // int maximumPoints(vector<vector<int>>& arr) {
    //     return solve(0,arr,-1);
    // }
    
    //<=======MEMORIZATION========>
    
    // int solve(int ind,vector<vector<int>>&arr, int last,vector<vector<int>>&dp){
    //     if(ind>=arr.size())
    //     return 0;
        
    //     if(dp[ind][last+1]!=-1)
    //     return dp[ind][last+1];
        
    //     int running=0;
    //     if(last!=0)
    //     running=arr[ind][0]+solve(ind+1,arr,0,dp);
        
    //     int fighting=0;
    //     if(last!=1)
    //     fighting=arr[ind][1]+solve(ind+1,arr,1,dp);
    
    //     int learning=0;
    //     if(last!=2)
    //     learning=arr[ind][2]+solve(ind+1,arr,2,dp);

    //     return dp[ind][last+1]=max(running,max(fighting,learning));
        
    // }
    
    
    // int maximumPoints(vector<vector<int>>& arr) {
    //     int n=arr.size();
    //     vector<vector<int>>dp(n+1,vector<int>(4,-1));
        
    //     return solve(0,arr,-1,dp);
    // }
    
    //<=========TABULATION=========>
    
    int maximumPoints(vector<vector<int>>& arr) {
    int n = arr.size();

   
    vector<vector<int>> dp(n, vector<int>(4, 0));

    
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]); 
    dp[0][2] = max(arr[0][0], arr[0][1]); 
    dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]}); 

   
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int val = arr[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], val);
                }
            }
        }
    }

    return dp[n - 1][3]; 
}
};