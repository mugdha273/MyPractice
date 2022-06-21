class Solution {
public:
    void dfs(vector<vector<int>>&image, int i, int j, int color, int x)
    {
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size()) return;
        
        if(image[i][j]==color||image[i][j]!=x) return;
        
        image[i][j]=color;
        
        dfs(image,i+1,j,color,x);
        dfs(image,i-1,j,color,x);
        dfs(image,i,j+1,color,x);
        dfs(image,i,j-1,color,x);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x= image[sr][sc];
        dfs(image,sr,sc,color,x);
        
        return image;
        
    }
};