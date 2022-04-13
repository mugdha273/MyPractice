class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;
        int ans = 1,res = 0;
        int e = INT_MIN;
        for(auto x:mp)
        {
            if(x.first!=1+e) ans=1;
            else if(x.first == e+1) ans++;
            e = x.first;
            res = max(res,ans);
        }
        return res;
        
    }
};