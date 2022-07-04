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
        vector<int>dp2(n);
        dp2[0]=0;
        dp2[1]= nums[1];
        
        for(int i=2; i<n; i++)
        {
            dp2[i]= max(dp2[i-1], nums[i]+ dp2[i-2]);
        }
        int possible_answer2= dp2[n-1];
        
        return max(possible_answer1,possible_answer2);
        
    }
};