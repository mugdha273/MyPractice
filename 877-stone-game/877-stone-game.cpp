class Solution {
public:
    // bool stoneGame(vector<int>& piles) {
    //     return true;
    // }
    
    int dp[1005][1005];
    
    int f(int st, int end, vector <int> &piles) {
        if(st == end-1) return max(piles[st], piles[end]);
        
        if(dp[st][end] != -1) return dp[st][end];
        
        int ifleft = piles[st] + max(f(st+2, end, piles), f(st+1, end-1, piles));
        int ifright = piles[end] + max(f(st+1, end-1, piles), f(st, end-2, piles));
        
        return dp[st][end] = max(ifleft, ifright);
    }
    bool stoneGame(vector<int>& piles) {
        int l = 0, r = piles.size()-1;
        memset(dp, -1, sizeof(dp));
        int alex = f(l, r, piles);
        int sum = 0;
        for(int i=0;i<piles.size();i++) sum += piles[i];

        return alex > (sum - alex);
    }
};