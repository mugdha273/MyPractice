class Solution {
public:
//     int dp[201][20001];
    
//     bool helper(vector<int>&nums, int k, int n)
//     {
//         if (n <= 0 || k <= 0)
//             return k == 0;
            
//         if(dp[n][k]!=-1) return dp[n][k];
        
//         if(nums[n-1]>k) return dp[n][k] = helper(nums,k,n-1);
//         return dp[n][k]= helper(nums,k,n-1)||helper(nums,k-nums[n-1],n-1);
//     }
    
//     bool canPartition(vector<int>& nums) {
//         int sum=0;
//         memset(dp,-1,sizeof(dp));
        
//         for (auto x: nums) sum+=x;
        
//         if(sum%2!=0) return false;
        
//         else
//         {
//             int sz = nums.size();
//             sum = sum/2;
//             return helper(nums, sum, sz);
//         }
//     }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % 2 == 1) return false;        
        int subsetSum = totalSum / 2;
        const int n = nums.size();

        vector<vector<int> > dp( n + 1, vector<int>(subsetSum + 1, 0));
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++){
            int cur = nums[i - 1];
            for(int j = 0; j <= subsetSum; j++){
                if(j >= cur) dp[i][j] = dp[i-1][j] || dp[i-1][j-cur];
                else dp[i][j] = dp[i-1][j];
                if(dp[n][subsetSum]) return true;
            }
        }
        return dp[n][subsetSum];   
        

    }
    
};