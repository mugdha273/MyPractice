class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int tot=0;
        int n= nums.size();
        
        for(auto x:nums) tot+=x;
        
        if(tot==nums[0]) return 0;
        
        for(int i=0;i<n-1; i++)
        {
            sum+= nums[i];
            if(sum== tot-(sum+nums[i+1])) return i+1;
        }
        
        return -1;
    }
};