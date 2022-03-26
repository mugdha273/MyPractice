class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int end = nums.size()-1;
        int start = 0;
        
        
        
        while(start<=end)
        {
            int mid =  start + (end-start)/2;
            
            if(nums[mid]< target)
            {
                start = mid+1;
            }
            else if (nums[mid]> target)
            {
                end = mid-1;
            }
            else
            {
                return mid;
            }
        }
        
        return -1;
    }
};