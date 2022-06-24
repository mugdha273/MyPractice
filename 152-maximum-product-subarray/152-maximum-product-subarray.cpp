class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int cpro=1;
        int ans= INT_MIN;
        
        for(int i=0; i<nums.size();i++)
        {
            cpro = cpro*nums[i];
            ans= max(ans, cpro);
            if(cpro==0) cpro=1;
        }
        
        cpro= 1;
        
        for(int i=nums.size()-1; i>=0;i--)
        {
            cpro = cpro*nums[i];
            ans= max(ans, cpro);
            
            if(cpro==0) cpro=1;
        }
        
        return ans;
        
    }
};