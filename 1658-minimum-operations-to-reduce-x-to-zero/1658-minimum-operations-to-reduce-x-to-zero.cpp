class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int i=0,j=0,sum1=0,sum2=0,len=0;
        
        for(auto x:nums)sum1+=x;
        sum1-=k;
        
        if(sum1==0) return nums.size();
        
        for(j=0; j<nums.size();j++)
        {
            sum2+=nums[j];
            while(sum2>sum1 && i<nums.size()) sum2-=nums[i++];
            if(sum2==sum1)
            {
                len=max(len,j-i+1);
            }
        }
        
        if(!len) return -1;
        
        return nums.size()-len;
        
    }
};