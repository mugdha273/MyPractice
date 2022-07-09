class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>>v;
        vector<int>dp(2999,-1);
        
		for (int i = lo; i <= hi; i++)
		{
			int ans = 0;
			int x = i;
            if(dp[x]!=-1) v.push_back({dp[x], i});
            else
            {
                while (x != 1)
                {
                    if (x % 2)
                    {
                        x = 3 * x + 1;
                    }
                    else
                    {
                        x = x / 2;
                    }
                    ans++;
                }
                dp[x]=ans;
                v.push_back({ans, i});
            }
			
		}
		sort(v.begin(), v.end());
		return v[k - 1].second;
    }
};