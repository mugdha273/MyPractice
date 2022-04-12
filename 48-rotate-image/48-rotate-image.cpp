class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0; i<m; i++)
        {
            vector<int>temp;
            
            for(int j=0; j<n; j++)
            {
                temp.push_back(matrix[j][i]);
            }
            reverse(temp.begin(), temp.end());
            matrix.push_back(temp);
        }
        
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<n; i++)
        {
            matrix.pop_back();
        }
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<m; j++) 
  			cout<<matrix[i][j]<<" ";
        cout<<endl;
            
        }
		
    }
};