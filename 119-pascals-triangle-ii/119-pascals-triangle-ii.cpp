class Solution {
public:
    vector<int> getRow(int ri) {
     vector<vector<int>>ans;
        
     for(int i=0;i<=ri;i++){
         vector<int>res(i+1,1);
         
         for(int j=1;j<i;j++)res[j]=ans[i-1][j-1]+ans[i-1][j];
         ans.push_back(res);
     }
     return ans[ri];
    }
};