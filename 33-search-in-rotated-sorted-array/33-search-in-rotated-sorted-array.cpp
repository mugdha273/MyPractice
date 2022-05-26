class Solution {
public:
    int getmin(vector<int>& nums)
    {
        int high= nums.size()-1;
        int low = 0;
        int n= nums.size();
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[low]<nums[high]) return low;
            
            if(nums[mid]<= nums[(mid-1+n)%n] && nums[mid]<= nums[(mid+1)%n]) return mid;
            
            else if(nums[mid]>= nums[low]) low = mid+1;
            else high = mid-1;
        }
        
        return 0;
    }
    
    int binarySearch(int low, int high, int target, vector<int>& nums)
    {
        while(low<=high)
        {
            int mid = low+ (high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high= mid-1;
            else low=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int idx = getmin(nums);
        int n= nums.size();

        if(target> nums[n-1]) return binarySearch(0, idx-1, target, nums);
        return binarySearch(idx, n-1, target, nums);
    }
};