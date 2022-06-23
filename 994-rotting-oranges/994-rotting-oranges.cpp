class Solution {
public:
    //BFS que

    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        
        queue<pair<int,int>>q;

        int ans=0;
        int countFreshOranges=0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    countFreshOranges++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        while(countFreshOranges != 0 && !q.empty())
        {
            int sz= q.size();
            
            while(sz--)
            {
                pair<int,int>p= q.front();
                q.pop();

                int ax[4]= {0,0,-1,1};
                int ay[4]= {-1,1,0,0};

                for(int i=0;i<4;i++)
                {
                    int nx= ax[i]+p.first;
                    int ny = ay[i]+p.second;
                    
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                    {
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        countFreshOranges--;
                    }
                }
                
            }
            
            ans++;
        }
        
        return countFreshOranges == 0 ? ans : -1;;
        
    }
};