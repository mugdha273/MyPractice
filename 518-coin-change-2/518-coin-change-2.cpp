class Solution {
public:
    int dp[301][5001];
    
    int helper(int n, int amt, vector<int>&coins)
    {
        if (n == 0 || amt == 0)
            return amt == 0 ? 1 : 0;
        
        if(dp[n][amt]!=-1) return dp[n][amt];
        
        if(coins[n-1]>amt) return dp[n][amt]=helper(n-1,amt,coins);
        
         return dp[n][amt]= helper(n-1,amt,coins)+helper(n,amt-coins[n-1],coins);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return helper(coins.size(), amount, coins);
    }
};