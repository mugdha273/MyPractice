class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int i=0; int j=nums.size()-1;
        vector<int>vec;
        while(i<=j)
        {
            if(nums[i]+nums[j]==target) return {i+1,j+1};
            else if(nums[i]+nums[j]<target) i++;
            else j--;
        }
        
        return vec;
    }
};