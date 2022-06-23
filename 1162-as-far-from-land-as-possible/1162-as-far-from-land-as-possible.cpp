class Solution {
public:
    bool isValid(int x, int y, int m, int n,vector<vector<int>>& grid)
    {
        if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0) return true;
        
        return false;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int ax[4]= {-1,1,0,0};
        int ay[4]= {0,0,-1,1};
        
        int ans = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 1) q.push({ i, j });
			}
		}
        
        while(!q.empty())
        {
            pair<int,int>p = q.front();
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nx= ax[i]+p.first;
                int ny= ay[i] + p.second;
                
                if(isValid(nx,ny,grid.size(),grid[0].size(),grid))
               {
                    q.push({nx,ny});
                    grid[nx][ny]= grid[p.first][p.second] + 1;
                    ans= max(ans,grid[nx][ny]);
               }
            }
            
        }
        
        return ans>0?ans-1:-1;
        
    }
};