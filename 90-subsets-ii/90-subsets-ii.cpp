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
        
        //when you choose to select ith element
        sub.push_back(nums[i]);
        helper(nums,i+1,sub);
        
        
        //when you are skipping the element make sure you skipped the duplicate as well
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        
        sub.pop_back();
        helper(nums,i+1,sub); 
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>sub;
        helper(nums,0,sub);
        
        return ans;
    }
};