class Solution {
public:
    int dp[101][101];
    
    int helper(int i, int j, int m, int n, vector<vector<int>>&obstacleGrid)
    {
        if(i>=m || j>=n) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
           
        return dp[i][j]=helper(i,j+1,m,n,obstacleGrid)+helper(i+1,j,m,n,obstacleGrid);
    }
           
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1, sizeof(dp));
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        return helper(0,0,m,n,obstacleGrid);
    }
};