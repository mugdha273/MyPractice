class Solution {
public:
    
    vector<vector<int>>ans;
    
    void helper(vector<int>&nums, int i, vector<int>&sub)
    {
        if(i==nums.size())
        {
            ans.push_back(sub);
            return;
        }
        
        helper(nums,i+1,sub);
        sub.push_back(nums[i]);
        helper(nums,i+1,sub); 
        sub.pop_back();
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>sub;
        helper(nums,0,sub);
        return ans;
    }
};