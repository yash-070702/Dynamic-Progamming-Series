#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int nthUglyNumber(int n) {
    //     vector<int> ugly(n);
    //     ugly[0] = 1;

    //     // dp[i][0] = candidate from 2, dp[i][1] from 3, dp[i][2] from 5
    //     vector<vector<long long>> dp(n, vector<long long>(3, 0));

    //     int i2 = 0, i3 = 0, i5 = 0;
    //     for (int i = 1; i < n; i++) {
    //         dp[i][0] = ugly[i2] * 2LL;
    //         dp[i][1] = ugly[i3] * 3LL;
    //         dp[i][2] = ugly[i5] * 5LL;

    //         ugly[i] = min({dp[i][0], dp[i][1], dp[i][2]});

    //         if (ugly[i] == dp[i][0]) i2++;
    //         if (ugly[i] == dp[i][1]) i3++;
    //         if (ugly[i] == dp[i][2]) i5++;
    //     }

    //     return ugly[n - 1];
    // }

    //<=======RECURSION=========>

    // bool isUgly(int num){
    //     if(num<=0)
    //     return false;

    //     if(num==1)
    //     return true;

    //     if(num%2==0)
    //     return isUgly(num/2);

    //     if(num%3==0)
    //     return isUgly(num/3);

    //     if(num%5==0)
    //     return isUgly(num/5);

    //     return false;
    // }


    // int solve(int n , int curr, int count){
    //     if(count==n)
    //     return curr;

    //     int next=curr+1;

    //     if(isUgly(next))
    //     return solve(n,next,count+1);

    //     return solve(n,next,count);
    // }

    // int nthUglyNumber(int n){
        
    //     return solve(n,1,1);
    // }

    //<======MEMORIZATION==========>
//     unordered_map<int, bool> uglyMemo;


// bool isUgly(int num) {
//     if (num <= 0) 
//     return false;

//     if (num == 1) 
//     return true;

//     if (uglyMemo.count(num)) 
//     return uglyMemo[num]; 

//     bool result = false;

//     if (num % 2 == 0) 
//     result = isUgly(num / 2);

//     else if (num % 3 == 0)
//      result = isUgly(num / 3);

//     else if (num % 5 == 0)
//      result = isUgly(num / 5);

//     else result = false;

//     return uglyMemo[num] = result; 
// }


// int findUgly(int n, int current, int count) {
//     if (count == n) return current; 

//     int next = current + 1;

//     if (isUgly(next)) {
//         return findUgly(n, next, count + 1);
//     } else {
//         return findUgly(n, next, count);
//     }
// }

// int nthUglyNumber(int n) {
//     return findUgly(n, 1, 1); 
// }

 //<=======TABULATION========>

 long long nthUglyNumber(int n) {
    if (n <= 0) return 0;
    vector<long long> dp(n+1);
    dp[1] = 1;

    int i2 = 1, i3 = 1, i5 = 1;
    for (int i = 2; i <= n; ++i) {
        long long next2 = 2LL * dp[i2];
        long long next3 = 3LL * dp[i3];
        long long next5 = 5LL * dp[i5];
        long long nextUgly = min(next2, min(next3, next5));
        dp[i] = nextUgly;

        if (nextUgly == next2) ++i2;
        if (nextUgly == next3) ++i3;
        if (nextUgly == next5) ++i5;
    }

    return dp[n];
}

};