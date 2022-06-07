class Solution {
public:
    
    vector<vector<int>>ans;
    
    void generate(vector<int>nums, int idx)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx; i<nums.size();i++)
        {
            if(nums[idx]!=nums[i])
            {
                swap(nums[i],nums[idx]);
                generate(nums, idx+1);
            }
            else if (i==idx)
            {
                generate(nums, idx+1);
                
            }
        }
    }
        
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        generate(nums,0);
        
        return ans;
        
    }
};