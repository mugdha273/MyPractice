class Solution {
public:
    int dp[13][10001];
    int helper(int n, vector<int>&coins, int amt)
    {
        if(n == 0 || amt == 0)
            return (amt == 0) ? 0 : INT_MAX - 1;
        if(dp[n-1][amt]!=-1) return dp[n-1][amt];
        if(amt<coins[n-1]) return dp[n-1][amt] = helper(n-1, coins, amt);
        
        return dp[n-1][amt]= min(helper(n-1, coins, amt),1+ helper(n, coins, amt-coins[n-1]));
        
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans= helper(coins.size(),coins,amount);
        return ans==INT_MAX - 1?-1:ans;
    }
};