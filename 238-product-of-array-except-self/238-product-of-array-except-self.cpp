class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> v1(n);
        vector<int> v2(n);
        
        v1[0] = 1;
        for(int i = 1; i < n; i++){
            v1[i] = v1[i - 1] * nums[i - 1];
        }
        
        v2[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--) 
            v2[j] = v2[j + 1] * nums[j + 1];
        
        
        for (int k = 0; k < n; k++)
            ans[k]= v1[k] * v2[k];
        
        return ans;
        
    }
};