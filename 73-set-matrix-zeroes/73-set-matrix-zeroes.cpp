class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int>r;
        vector<int>c;
        int n= matrix.size();
        int m= matrix[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        
        for(auto x:r)
        {
            for(int j=0; j<m; j++)
            {
                matrix[x][j]=0;
            }
        }
        
        for(auto x:c)
        {
            for(int i=0; i<n; i++)
            {
   
                    matrix[i][x]=0;
            }
        }
        
        
        
        
//         for(auto x:r)
//         {
//             cout<<x<<" ";
//         }
        
//         cout<<"\n";
        
//         for(auto x:c)
//         {
//             cout<<x<<" ";
//         }
        
//         cout<<"\n";
        
        
        
    }
};