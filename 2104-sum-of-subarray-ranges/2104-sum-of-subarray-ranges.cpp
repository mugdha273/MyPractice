class Solution {
public:
    
    long long subArrayRanges(vector<int>& nums) {
        int n= nums.size();
        long long ans=0;
        int minE=nums[0];
        int maxE=nums[0];
        
        for(int i=0; i<n; i++)
        {
            int minE=nums[i];
            int maxE=nums[i];
            for(int j=i; j<n; j++)
            {
                maxE= max(nums[j], maxE);
                minE= min(nums[j],minE);
                // cout<<maxE<<" "<<minE<<endl;
                ans+= (maxE-minE);
            }
        }
        
        return ans;
        
    }
};