class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int m=0;
            int ans=0;
            for(int j=i-1;j>=0&&j>=i-k;j--)
            {
                m=max(m,arr[j]);
                ans=max(ans,m*(i-j)+dp[j]);
            }
            dp[i]=ans;
        }
        return dp[n];
    }
};