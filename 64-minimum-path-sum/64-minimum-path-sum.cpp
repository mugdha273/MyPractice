class Solution {
public:
//     int dp[100][100];
    
//     int helper(int i, int j, int m ,int n, vector<vector<int>>&grid,vector<vector<int>>&dp)
//     {
//         if(i==m-1 && j==n-1) return grid[m-1][n-1];
//         if(i>=m||j>=n) return 1000;
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         return dp[i][j] = min((grid[i][j]+ helper(i+1,j,m,n,grid,dp)), (grid[i][j]+ helper(i,j+1,m,n,grid,dp)));
//     }
    
//     int minPathSum(vector<vector<int>>& grid) {
//         int m= grid.size();
//         int n= grid[0].size();
//        vector<vector<int>> dp(m,vector<int>(n,-1));
        
//         return helper(0,0,m,n,grid,dp);
//     }
    
       int minPathSum(vector<vector<int>>& grid) {
            int m= grid.size();
            int n= grid[0].size();
           vector<vector<int>> dp(m,vector<int>(n,-1));

           
           for(int i=0; i<m; i++)
           {
               for(int j=0; j<n; j++)
               {
                   int a= 1000;
                   int b= 1000;
                   if(i==0 && j==0) dp[i][j]= grid[0][0];
                   
                   else{
                       if(i>0)
                       a= grid[i][j]+ dp[i-1][j];
                       if(j>0)
                           b= grid[i][j]+ dp[i][j-1];

                       dp[i][j]= min(a,b);
                   }
                   
               }
           }
           
            return dp[m-1][n-1];
        }
    
    
};