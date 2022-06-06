class Solution {
public:
    
    set<vector<int>>ans;
    
    void helper(vector<int>&nums, int i, vector<int>&sub)
    {
        if(i==nums.size())
        {
            ans.insert(sub);
            return;
        }
        
        helper(nums,i+1,sub);
        sub.push_back(nums[i]);
        helper(nums,i+1,sub); 
        sub.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>sub;
        helper(nums,0,sub);
        vector<vector<int>>res;
        for(auto x:ans) res.push_back(x);
        
        return res;
    }
};