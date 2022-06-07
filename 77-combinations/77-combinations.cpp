class Solution {
public:
    
    vector<vector<int>>ans;
    
    void helper(int k, vector<int>&nums, vector<int>&sub, int idx)
    {
        if(sub.size()==k)
        {
            ans.push_back(sub);
            return;
        }
        
        for(int i=idx; i<nums.size();i++)
        {
            sub.push_back(nums[i]);
            helper(k,nums,sub,i+1);
            sub.pop_back();
        }
        
    }    
    vector<vector<int>> combine(int n, int k) {
        vector<int>sub;
        vector<int>nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        
        helper(k,nums,sub,0);
        return ans;
    }
};