class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
         vector<int>ans;
         int calc=0;
         for(auto x:nums)
         {
            calc+=x;
            ans.push_back(calc);
         }
        
        return ans;
    }
};