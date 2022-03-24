class Solution {
public:
    
    int coinChange(vector<long long int>& coins, int sum) {
        int N = coins.size();
        int dp[N+1][sum+1];
        
         for(int i=0; i<sum+1; i++) dp[0][i] = INT_MAX-1;
        for(int j=1; j<N+1; j++) dp[j][0] = 0;
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1; j<=sum; j++)
            {
                
                
                if(coins[i-1]<=j)
                {
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        return dp[N][sum]== INT_MAX - 1 ? -1 :dp[N][sum] ;
        
        
    }
    
    int numSquares(int n) {
        
        int t = sqrt(n);
        
        vector<long long int>vec;
        
        for(int i=1; i<=t; i++)
        {
            vec.push_back(i*i);
        }
        
        // for(auto x:vec)
        // {
        //     cout<<x<<" ";
        // }
        
        return coinChange(vec, n);
        
    }
};