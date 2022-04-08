class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int ans=0;
        int minP = INT_MAX;
        
        for(int i=0; i<n; i++)
        {
            minP = min(minP, prices[i]);
            ans= max(ans, prices[i]-minP);
        }
        
        return ans;
    }
};