class Solution {
public:
//     int dp[13][10001];
//     int helper(int n, vector<int>&coins, int amt)
//     {
//         if(n == 0 || amt == 0)
//             return (amt == 0) ? 0 : INT_MAX - 1;
//         if(dp[n-1][amt]!=-1) return dp[n-1][amt];
//         if(amt<coins[n-1]) return dp[n-1][amt] = helper(n-1, coins, amt);
        
//         return dp[n-1][amt]= min(helper(n-1, coins, amt),1+ helper(n, coins, amt-coins[n-1]));
        
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         memset(dp,-1,sizeof(dp));
//         int ans= helper(coins.size(),coins,amount);
//         return ans==INT_MAX - 1?-1:ans;
//     }
    
    int coinChange(vector<int>& coins, int amt) {
        int n= coins.size();
        int dp[n+1][amt+1];
        
        for(int i=0; i<amt+1; i++) dp[0][i] = INT_MAX-1;
        for(int j=1; j<n+1; j++) dp[j][0] = 0;
        
        for(int i=1;i<=n; i++)
        {
            for(int j=1; j<=amt; j++)
            {
                if(coins[i-1]>j) dp[i][j]= dp[i-1][j];
                else dp[i][j]= min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
        }
        return dp[n][amt]== INT_MAX - 1 ? -1 :dp[n][amt] ;
    }
};