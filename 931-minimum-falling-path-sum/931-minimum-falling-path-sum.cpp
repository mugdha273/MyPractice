class Solution {
public:
    int dp[101][101];
    int helper(int i, int j, vector<vector<int>>& matrix, int n)
    {
        if(i>=n||j>=n||j<0) return INT_MAX;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=matrix[i][j]+ min({helper(i+1,j-1, matrix, n), helper(i+1, j,matrix, n), helper(i+1,j+1,matrix, n)});
                    
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        
        for(int i=0; i<matrix.size(); i++)
        {
            ans= min(ans,helper(0,i,matrix, matrix.size()));
        }
        return ans;
    }
};