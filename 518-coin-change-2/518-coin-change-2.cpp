class Solution {
public:
    int change(int sum, vector<int>& coins) {
        int n = coins.size();
        int dp[n+1][sum+1];
        for(int i=0; i<sum+1; i++) dp[0][i] = 0;
        for(int j=1; j<n+1; j++) dp[j][0] = 1;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(coins[i-1] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][sum];
        
    }
};