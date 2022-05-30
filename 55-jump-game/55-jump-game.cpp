class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int boundary = nums[0];
        int n= nums.size()-1;
        
        for(int i=0; i<=boundary ; i++)
        {
            if(i+nums[i]>=boundary)
            {
                boundary= i+nums[i];
            }
            if(boundary>=n) return true;
        }
        
        return false;
        
    }
};