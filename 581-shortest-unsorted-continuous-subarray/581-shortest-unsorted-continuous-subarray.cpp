class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v;
        v= nums;
        sort(v.begin(), v.end());
        int s=0;
        int e=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=v[i])
            {
                s=i;
                break;
            }
        }
        
        for(int i=s; i<nums.size(); i++)
        {
            if(nums[i]!=v[i])
            {
                e=i;
            }
        }
        if(e==0 && s==0) return 0;
        
        return e-s+1;
    }
};