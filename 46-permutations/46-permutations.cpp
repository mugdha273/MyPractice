class Solution {
public:
    vector<vector<int>>vec;
    
    void helper(int idx, vector<int>& nums)
    {
        if(idx==nums.size()){
            vec.push_back(nums);
        }
        
        for(int i=idx; i<nums.size(); i++)
        {
            swap(nums[idx],nums[i]);
            helper(idx+1,nums);
            swap(nums[idx],nums[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        helper(0,nums);
        return vec;
    }
};