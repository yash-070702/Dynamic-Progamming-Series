#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //<========MEMORIZATION=======>
    
    
    
    // int lisEndingAt(int idx, vector<int>& nums, vector<int>& dp) {
    //     if (dp[idx] != -1) return dp[idx];

    //     int best = 1; // at least the element itself
    //     for (int prev = 0; prev < idx; prev++) {
    //         if (nums[prev] < nums[idx]) {
    //             best = max(best, 1 + lisEndingAt(prev, nums, dp));
    //         }
    //     }
    //     return dp[idx] = best;
    // }

    // int ldsStartingAt(int idx, vector<int>& nums, vector<int>& dp) {
    //     if (dp[idx] != -1) return dp[idx];

    //     int best = 1;
    //     for (int next = idx + 1; next < nums.size(); next++) {
    //         if (nums[next] < nums[idx]) {
    //             best = max(best, 1 + ldsStartingAt(next, nums, dp));
    //         }
    //     }
    //     return dp[idx] = best;
    // }

    // int LongestBitonicSequence(int n , vector<int>& nums) {
    
    //     vector<int> lis(n, -1), lds(n, -1);

    //     // fill LIS and LDS
    //     for (int i = 0; i < n; i++) lisEndingAt(i, nums, lis);
    //     for (int i = n - 1; i >= 0; i--) ldsStartingAt(i, nums, lds);

    //     int ans = 0;
    //     for (int i = 0; i < n; i++) {
    //         ans = max(ans, lis[i] + lds[i] - 1);
    //     }
    //     return ans;
    // }
    
    //<=======TABULATION=======>
    
    
    int LongestBitonicSequence(int n, vector<int> &a) {


    int ans = 0;

    vector<int> lis(n,0);

    vector<int> lds(n,0);

    for(int i=0,j=n-1;i<n && j>=0; i++,j--){

     int fmx = 0, rmx = 0;

     for(int x=i,y=j;x>=0 && y<n;x--,y++){

      if(a[x] < a[i])

          fmx = max(fmx,lis[x]);

      if(a[y] < a[j])

          rmx = max(rmx,lds[y]);

     }

     lis[i]=fmx+1;

     lds[j]=rmx+1;

    }

    for(int i = 0; i<n;i++){

        int v = lis[i]+lds[i]-1;

        if(v==lis[i] || v==lds[i])

            continue;

     ans = max(ans,v);

    }

 return ans;

    }
};
