class Solution {
public:
 //<----------MEMORIZATION------->
//int climbstairs(int n, vector<int>& memo) {
     
    //     if (n == 0 || n == 1) return 1;

    //     if (memo[n]!=-1) {
    //         return memo[n]; 
    //     }

        
    //     memo[n] = climbstairs(n - 1, memo) + climbstairs(n - 2, memo);
    //     return memo[n];
    // }

    // int climbStairs(int n) {
    //       vector<int> memo(n+1,-1);
    //     return climbstairs(n, memo);
    // }


   // <----------TABULATION--------->
    //  int climbStairs(int n) {
    //     vector<int> memo(n+1,-1);

    //     if(n==1 || n==0)
    //     return n;

    //     memo[0]=1;
    //     memo[1]=1;

    //     for(int i=2;i<=n;i++){
    //         memo[i]=memo[i-1]+memo[i-2];
    //     }
    //     return memo[n];
    // }

       //<---------SPACE OPTIMIZATION--------->
       int climbStairs(int n) {
       int n1=1;
       int n2=1;
       int steps=0;

       if(n==1 || n==0)
       return n;

       for(int i=2;i<=n;i++){
       steps=n1+n2;
       n1=n2;
       n2=steps;
     }
     return steps;
       }
};
