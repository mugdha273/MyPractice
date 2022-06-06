class Solution {
public:
    vector<vector<int>>ans;
    
    void generate(vector<int>& nums, int idx)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        else{
            for(int i=idx; i<nums.size(); i++)
            {
                swap(nums[idx], nums[i]);
                generate(nums, idx+1);
                swap(nums[idx], nums[i]);
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        generate(nums,0);
        return ans;
    }
};