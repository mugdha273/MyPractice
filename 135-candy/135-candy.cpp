class Solution {
public:
    int candy(vector<int>& a) {
        
        int res=0;
        int n= a.size();
        vector<int>nums(n,1);
        
        for(int i=1; i<n; i++)
        {
            if(a[i]>a[i-1])
            {
                nums[i] = nums[i-1]+1;
            }
        }
        
        for(int i=n-2; i>=0; i--)
        {
            if(a[i]>a[i+1])
            {
                nums[i] = max(nums[i],nums[i+1]+1);
            }
        }
        
        for(auto x:nums) res+=x;
        
        return res;
        
    }
};