class Solution {
public:
    int dp[201][20001];
    
    bool helper(vector<int>&nums, int k, int n)
    {
        if (n <= 0 || k <= 0)
            return k == 0;
            
        if(dp[n][k]!=-1) return dp[n][k];
        
        if(nums[n-1]>k) return dp[n][k] = helper(nums,k,n-1);
        return dp[n][k]= helper(nums,k,n-1)||helper(nums,k-nums[n-1],n-1);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        
        for (auto x: nums) sum+=x;
        
        if(sum%2!=0) return false;
        
        else
        {
            int sz = nums.size();
            sum = sum/2;
            return helper(nums, sum, sz);
        }
    }
};