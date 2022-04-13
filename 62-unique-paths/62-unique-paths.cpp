class Solution {
public:
    int mem[101][101];
    
    int helper(int i, int j, int m, int n)
    {
        if(i == m-1 && j== n-1) return 1;
        else if(i>= m || j>=n) return 0;
        
        if(mem[i][j]!=-1) return mem[i][j];
        else mem[i][j] = helper(i+1, j, m, n)+helper(i, j+1, m, n);
        
        return mem[i][j];
        
    }
    
    int uniquePaths(int m, int n) {
        memset(mem,-1, sizeof(mem));
        return helper(0,0,m,n);
    }
};