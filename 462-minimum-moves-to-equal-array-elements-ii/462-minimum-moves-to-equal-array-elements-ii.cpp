class Solution {
public:
    
    
    long long int helper(int med, vector<int>&nums)
    {
        long long int sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+= abs(nums[i]-nums[med]);
        }
        return sum;
    }
    
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() ,nums.end());
        int n= nums.size();
        
        if(n==1) return 0;
        if(n==2) return abs(nums[0]-nums[1]);
        
        int med;
        if(n%2==0)
        {
            int a= n/2-1;
            int b= n/2+1;
            return min(helper(a,nums), helper(b,nums));
        }
        
        
        return helper(n/2, nums);
    }
};