class Solution {
public:
    int dp[50002][2];
    
    int helper(int state, int fee, vector<int>&prices, int idx)
    {
        if(idx>=prices.size()) return 0;
        int profit=0;
        if(dp[idx][state]!=-1) return dp[idx][state];
        
        if(state==0)
        {
            int Buy= helper(1, fee, prices, idx+1)-prices[idx];
            int notBuy= helper(0, fee,prices, idx+1);
            profit= max(Buy,notBuy);
        }
        if(state==1)
        {
            int sell= helper(0, fee, prices,idx+1)+prices[idx]-fee;
            int notSell= helper(1,fee,prices,idx+1);
            profit= max(sell,notSell);
        }
        return dp[idx][state]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return helper(0,fee,prices,0);
    }
};