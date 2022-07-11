//https://www.youtube.com/watch?v=rSi4MpGEz1M

class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1,0);
        int ans{0};
        for(int i=2; i<n; i++)
        {
            if(nums[i-1]-nums[i]== nums[i-2]-nums[i-1])
            {
                dp[i]= dp[i-1]+1;
                ans+=dp[i];
            }
        }
        return ans;
    }
};