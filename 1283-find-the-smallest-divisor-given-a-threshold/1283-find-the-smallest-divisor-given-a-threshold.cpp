class Solution {
public:
    long long int calculate(vector<int>nums, int k)
    {
        long long int h=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%k==0) h+= nums[i]/k;
            else h+= (nums[i]/k)+1;
        }
        return h;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1; int r= 10000000;
        int ans=0;
        
        while(l<=r)
        {
            int mid= l+ (r-l)/2;
            long long int h= calculate(nums,mid);
            
            if(h>threshold){
                l=mid+1;
            }
            else if(h<=threshold){
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};