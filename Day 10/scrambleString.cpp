#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//<=========RECURSIVE==========>
    
//     bool solve(string s1, string s2){
//         int n=s1.length();

//         if(s1.length()!=s2.length())
//         return false;

//         if(s1==s2)
//         return true;

//        for(int i = 1; i < n; i++) {
    
//     bool notSwapped = solve(s1.substr(0,i), s2.substr(0,i)) &&
//                       solve(s1.substr(i),   s2.substr(i));

//     bool swapped = solve(s1.substr(0,i),   s2.substr(n-i)) &&
//                    solve(s1.substr(i),     s2.substr(0,n-i));

//     if(notSwapped || swapped) return true;
// }

//         return false;
//     }
   
//     bool isScramble(string s1, string s2) {
//         return solve(s1,s2);
//     }

//<=========MEMORIZATION===========>

    bool solve(string s1, string s2,unordered_map<string,bool>&mp){
        int n=s1.length();

        if(s1.length()!=s2.length())
        return false;

        if(s1==s2)
        return true;

        string key=s1+"-"+s2;

        if(mp.find(key)!=mp.end())
        return mp[key];

       for(int i = 1; i < n; i++) {
    
    bool notSwapped = solve(s1.substr(0,i), s2.substr(0,i),mp) &&
                      solve(s1.substr(i),   s2.substr(i),mp);

    bool swapped = solve(s1.substr(0,i),   s2.substr(n-i),mp) &&
                   solve(s1.substr(i),     s2.substr(0,n-i),mp);

    if(notSwapped || swapped) return true;
}

        return mp[key]=false;
    }
   
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool>mp;

        return solve(s1,s2,mp);

    }
};