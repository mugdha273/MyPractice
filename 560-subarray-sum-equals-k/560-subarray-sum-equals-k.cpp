class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int res=0, sum=0;
        mp[0]=1;
        for(auto x: nums)
        {
            sum+=x;
            res+= mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};