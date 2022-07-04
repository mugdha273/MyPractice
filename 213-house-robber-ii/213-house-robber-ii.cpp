class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        int n= nums.size();
        vector<int>dp(n);
        
        //Rob first house
        dp[0]=nums[0];
        dp[1]= max(nums[0], nums[1]);
        
        for(int i=2; i<n-1; i++)
        {
            dp[i]= max(dp[i-1], nums[i]+ dp[i-2]);
        }
        int possible_answer1= dp[n-2];
        
        //Rob last house
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i=2 ; i<nums.size() ; i++)
            dp[i] = max( nums[i]+ dp[i-2], dp[i-1] );
        int possible_answer2= dp[n-1];
        
        return max(possible_answer1,possible_answer2);
        
    }
};