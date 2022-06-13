class Solution {
public:
    int dp[201][201];
    int rec(vector<vector<int>>& t, int i, int j)
    {
        if(i==t.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=t[i][j]+min(rec(t,i+1,j), rec(t,i+1,j+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return rec(triangle,0,0);
    }
};