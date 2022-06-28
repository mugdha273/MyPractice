class Solution {
public:
    bool check(vector<int>&nums, int target)
    {
        int x=0;
        for(auto y:nums) x+= y;
        
        if(x<target) return false;
        
        return true;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        if(check(nums, target)==false) return 0;
        
        int l{0},r{0},sum{0};
        int ans=INT_MAX;
        
        while(r<nums.size())
        {
            sum+=nums[r];
            if(sum>=target)
            {
                while(sum>=target)
                {
                    sum=sum-nums[l];
                    l++;
                }
            ans=min(ans,r-l+2);
            }
            r++;
        }

        return ans;
    }
};