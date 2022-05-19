/*Approach 1: find maximum element-> O(n)
Approach 2: find nums[i]>nums[i-1] && nums[i]>nums[i+1] and then break
-> O(n) */

//Appraoch 3: Binary Search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int l=0, r= nums.size()-1;
        
        while(l<r)
        {
            int mid = l + (r-l)/2;
            
            if(nums[mid]<nums[mid+1]) l= mid+1;
            else r = mid;
        }
        
        return l;
    }
};