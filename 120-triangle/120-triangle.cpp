class Solution {
public:
    int dp[201][201];
    
    int helper(int i, int j, vector<vector<int>>&triangle)
    {
        if(i>= triangle.size()||j>=triangle[i].size()) return 0;
        if(i==triangle[i].size()) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=min(triangle[i][j]+helper(i+1,j,triangle), triangle[i][j]+helper(i+1,j+1,triangle));
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,triangle);
    }
};