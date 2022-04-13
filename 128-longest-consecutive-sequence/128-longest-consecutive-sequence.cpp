class Solution {
public:
    int longestConsecutive(vector<int>& p) {
        if(p.size()==0) return 0;
        if(p.size()==1) return 1;
        set<int>s;
        for(auto x:p) s.insert(x);
        vector<int>nums;
        for(auto x:s)
            nums.push_back(x);
        if(nums.size()==1) return 1;
        int len=1;
        int ans=0;
//         for(auto x:nums)
//         {
//             cout<<x<<" ";
//         }
//         cout<<"\n";
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1]-nums[i]==1)
            {
                len++;
                ans = max(ans, len);
            }
            else
            {
                ans = max(ans, len);
                len=1;
            }
        }
        return ans;
    }
};