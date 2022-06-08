class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int currSum=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            sum = max(currSum,sum);
            if(currSum<0)
            {
                currSum=0;
            }
            currSum+= nums[i];
        }
        
        return max(currSum,sum);
    }
};