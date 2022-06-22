class Solution {
public:
    void helper(vector<vector<int>>& grid, int i, int j, int &a)
    {
        int m = grid.size(), n = grid[0].size();
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j]) {
            a++;
            grid[i][j]=0;
            helper(grid, i - 1, j, a);
            helper(grid, i + 1, j, a);
            helper(grid, i, j - 1, a);
            helper(grid, i, j + 1, a);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int a=0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int a = 0;
                    helper(grid, i, j, a);
                    ans = max(ans, a);
                }
            }
        }
        return ans;
        
    }
};