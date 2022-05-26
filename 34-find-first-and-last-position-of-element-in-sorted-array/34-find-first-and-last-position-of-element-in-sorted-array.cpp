class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, res=-1;
        vector<int>ans;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[mid]==target)
            {
                res=mid;
                high = mid-1;
            }
            else if(nums[mid]>target) high= mid-1;
            else low = mid+1;
        }
        ans.push_back(res);
        
        low = 0, high = nums.size()-1, res=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[mid]==target)
            {
                res=mid;
                low = mid+1;
            }
            else if(nums[mid]>target) high= mid-1;
            else low = mid+1;
        }
        ans.push_back(res);
        
        return ans;
    }
};