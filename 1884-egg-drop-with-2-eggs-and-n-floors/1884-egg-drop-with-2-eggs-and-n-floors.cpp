class Solution {
public:
    int dp[1001][3];
    
    int solve(int f, int e)
    {
        if(f==0||f==1) return 1;
        if(e==1) return f;
        int ans=INT_MAX;
        
        if(dp[f][e]!=-1) return dp[f][e];
        
        for(int k=1; k<=f; k++)
        {
            int temp= 1+max(solve(k-1,e-1), solve(f-k,e));
            ans= min(ans,temp);
        }
        return dp[f][e]=ans;
    }
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,2);
    }
};