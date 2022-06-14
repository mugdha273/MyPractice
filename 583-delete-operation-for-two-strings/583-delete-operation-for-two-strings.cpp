class Solution {
public:
    int dp[501][501];
    
    int lcs(string s, string p, int n, int m)
    {
        if(n==0||m==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[n-1]==p[m-1]) return dp[m][n]= 1+lcs(s,p,n-1,m-1);
        
        return dp[m][n]= max(lcs(s,p,n-1,m), lcs(s,p,n,m-1));
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int n= word1.size();
        int m= word2.size();
        int k =lcs(word1, word2, n,m);
        
        return m-k+n-k;
        
    }
};