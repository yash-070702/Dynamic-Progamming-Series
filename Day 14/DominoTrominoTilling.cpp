#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
const int MOD = 1e9 + 7;

//<=========RECURSION=========>

// int full(int n) {
//     if (n == 0) return 1;
//     if (n == 1) return 1;
//     if (n == 2) return 2;

//     return (full(n - 1) + full(n - 2) + 2 * partial(n - 1)) % MOD;
// }

// int partial(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 0;
//     if (n == 2) return 1;

//     return (full(n - 2) + partial(n - 1)) % MOD;
// }

// int numTilings(int n) {
//     return full(n);
// }

//<=====MEMORIZATION========>

vector<int> fullDP, partialDP;


int full(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (fullDP[n] != -1) return fullDP[n];

    return fullDP[n] = ((long long)full(n - 1) + full(n - 2) + 2LL * partial(n - 1)) % MOD;
}

int partial(int n) {
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;

    if (partialDP[n] != -1) return partialDP[n];

    return partialDP[n] = ((long long)full(n - 2) + partial(n - 1)) % MOD;
}

int numTilings(int n) {
    
    fullDP.assign(n + 1, -1);
    partialDP.assign(n + 1, -1);
    return full(n);
}
};