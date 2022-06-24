class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int n= nums.size()-1;
        int boundary=nums[0];
        
        for(int i=0; i<=boundary; i++)
        {
            if(boundary<= i+nums[i]) boundary= i+nums[i];
            if(boundary>=n) return true;
            // cout<<boundary<<" ";
        }
        
        return false;
        
    }
};