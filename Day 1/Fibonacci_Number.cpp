class Solution {
public:
 // <----------MEMORIZATION----------->
    // int solve(int n , vector<int>&dp){
    //  if(n==0 || n==1)
    //  return n;

    //  if(dp[n]!=-1)
    //  return dp[n];

    //  return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    // }
    
    // int fib(int n) {
    // vector<int>dp(n+1,-1);
    
    // return solve(n,dp);
    // }

    
// <---------TABULATION----------->
    // int fib(int n){

    //     if(n==1 || n==0)
    //     return n;

    //     vector<int>dp(n+1,-1);
    //     dp[0]=0;
    //     dp[1]=1;

    //     for(int i=2;i<=n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }

    // <---------SPACE OPTIMIZATION--------->
    int fib(int n){
        int n1=0;
        int n2=1;
        int number=0;
         if(n==1 || n==0)
         return n;
         
         for(int i=2;i<=n;i++){
            number=n1+n2;
            n1=n2;
            n2=number;
         }
         return number;
    }
};

