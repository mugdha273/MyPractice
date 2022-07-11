class Solution {
public:
    int dp[366];
    int helper(int idx, vector<int>&days, vector<int>&costs)
    {
        if(idx>=days.size()) return 0;
        
        int n= days.size();
        int i=idx;
        if(dp[idx]!=-1) return dp[idx];
        int a=costs[0]+helper(idx+1,days,costs);
          
        for(i= idx; i<n; i++)
        {
            if(days[i]>=days[idx]+7)
            {
                break;
            }
            
        }
        int b= costs[1]+helper(i,days,costs);
        for(i= idx; i<n; i++)
        {
            if(days[i]>=days[idx]+30)
            {
                break;
            }
            
        }
        
        int c= costs[2]+helper(i,days,costs);

        return dp[idx]=min({a,b,c});
       
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return helper(0,days,costs);
    }
};