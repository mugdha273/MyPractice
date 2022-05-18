class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int t= n-1;
        int z=0;
        
        for(int i=0; i<n; i++)
        {
            while(nums[i]==2 && i<=t)
            {
                swap(nums[i], nums[t--]);
            }
            while(nums[i]==0 && i>=z)
            {
                swap(nums[i], nums[z++]);
            }
        }
        
    }
};