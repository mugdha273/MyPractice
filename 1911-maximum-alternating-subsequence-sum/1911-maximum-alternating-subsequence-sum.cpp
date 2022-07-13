class Solution {
public:
    //Mahhhn! I'm so proud! I wrote the recursive solution all by myself in one go.
    long long dp[100000][2];
    long long helper(vector<int>&nums, int i, int state)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        long long a=INT_MIN;
        if(dp[i][state]!=-1) return dp[i][state];
        if(state==0)
        {
          long long take= helper(nums,i+1,1)+nums[i];
          long long notTake=helper(nums,i+1,0)+0;
          a= max(take,notTake);
        }
        else if(state==1)
        {
          long long take= helper(nums,i+1,0)-nums[i];
          long long notTake=helper(nums,i+1,1)-0;
          a= max(take,notTake);
        }
        return dp[i][state]=a;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(nums,0,0);
    }
};