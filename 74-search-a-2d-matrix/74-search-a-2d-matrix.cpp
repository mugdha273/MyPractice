class Solution {
public:
    bool binSearch(vector<int>vec, int target)
    {
        int l=0, h= vec.size()-1;
        
        while(l<=h)
        {
            int mid = (l+h)/2;
            
            if(vec[mid] == target ) return true;
            if(vec[mid]> target) h= mid-1;
            else l = mid+1;
        }
       
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // cout<<matrix.size()<<endl;
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                // cout<<j<<" ";
                if(target<= matrix[i][matrix[i].size()-1] && target >= matrix[i][0])
                {
                    return binSearch(matrix[i], target);
                }
            }
            // cout<<endl;
        }
       return false; 
    }
};