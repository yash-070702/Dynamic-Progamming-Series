#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

vector<int>nextSmaller(vector<int>&arr){
    stack<int>st;
    st.push(-1);
    vector<int>ans1(arr.size());

    for(int i=arr.size()-1;i>=0;i--){
        
            while(st.top()!=-1 && arr[st.top()]>=arr[i])
            st.pop();

            ans1[i]=st.top();
        // }
        st.push(i);
    }
    return ans1;
}

vector<int>prevSmaller(vector<int>&arr){
     stack<int>st;
    st.push(-1);
    vector<int>ans1(arr.size());

    for(int i=0;i<arr.size();i++){
        
            while(st.top()!=-1 && arr[st.top()]>=arr[i])
            st.pop();

            ans1[i]=st.top();
        st.push(i);
    }
    return ans1;
}


    int largestRectangleArea(vector<int>& arr) {

        vector<int>next=nextSmaller(arr);
        vector<int>prev=prevSmaller(arr);

  int maxArea=-1;
  int area;
   for(int i=0;i<arr.size();i++){
    
    if(next[i]==-1)
    next[i]=arr.size();

    area= arr[i] * (next[i]-prev[i]-1);
    maxArea=max(maxArea,area);
   }

   return maxArea;
    }


int maxArea(vector<vector<int>>& matrix) {
        vector<vector<int>>v;

        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            vector<int>t;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j]);
            }
            v.push_back(t);
        }

        

         int area=largestRectangleArea(v[0]);

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){

                if(v[i][j])
                v[i][j]+=v[i-1][j];

                else
                v[i][j]=0;
            }
            area=max(area,largestRectangleArea(v[i]));
        }

        return area;
        
    }
};