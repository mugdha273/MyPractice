class Solution {
public:
    int findMin(vector<int>& nums) {
        int high= nums.size()-1;
        int low=0;
        int n = nums.size();
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[low]<=nums[high]) return nums[low];
            if(nums[mid]<= nums[(mid+1)%n] && nums[mid]<=nums[(mid+n-1)%n]) return nums[mid];
            else if(nums[mid]>= nums[low]) low = mid+1;
            else high= mid-1;
        }   
        
        return -1;
    }
};