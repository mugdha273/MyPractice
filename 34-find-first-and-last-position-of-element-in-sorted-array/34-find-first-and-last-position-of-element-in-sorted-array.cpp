class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l=0, r = nums.size()-1;
        vector<int>ans = {-1,-1};
        
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            cout<<mid<<endl;
            if(nums[mid]==target)
            {
                int i=mid, j=mid;
                
                while(i>=0 && nums[i]==target)
                {
                    i--;
                }
                while(j<nums.size() && nums[j]==target) j++;
                
                ans[0]=i+1;
                ans[1]=j-1;
                cout<<i<<" "<<j<<endl;
                return ans;
            }
            if (nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
        }
        
        return ans;
    }
};