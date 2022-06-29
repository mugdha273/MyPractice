class Solution {
public:
    
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n= nums.size();
        // if(n<3) return -1;
        
        std::vector<int>::iterator low;
        int ans=0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++){
                int k = nums[i]+nums[j];
                int idx = lower_bound(nums.begin() + j + 1, nums.end(), k) - nums.begin() - 1;
                ans += (idx - j);
            }
        }
        
        return ans>0?ans:0;
    }
};