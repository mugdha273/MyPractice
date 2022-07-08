class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        
        vector<vector<int>>vec(m,vector<int>(n,0));
        
        for(int i=0; i<n; i++) if(matrix[0][i])vec[0][i]=1;
        for(int i=0; i<m; i++) if(matrix[i][0])vec[i][0]=1;
        
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i][j]==0) vec[i][j]=0;
                else vec[i][j] = min({vec[i-1][j-1],vec[i-1][j],vec[i][j-1]})+1;
            }
            
        }
        int ans=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans+=vec[i][j];
                // cout<<vec[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return ans;
    }
};