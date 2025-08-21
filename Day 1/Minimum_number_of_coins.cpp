#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    vector<int> minPartition(int N) {
        vector<int> result;
        vector<int> currency = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        
        int i = currency.size() - 1; 
        
        while (N > 0 && i >= 0) {
            while (currency[i] > N)
                i--; 
            
            int num = N / currency[i]; 
            N -= num * currency[i];    
            
            vector<int> temp(num, currency[i]);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        
        return result;
    }
    
 
};
