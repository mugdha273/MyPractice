
class Solution {
public:
    vector<vector<int>> ans;
    void permute(vector<int>a, int l, int r)
    {
        if(l==r) ans.push_back(a);
        else
        {
            for(int i=l; i<r; i++)
            {
                swap(a[l], a[i]);
                
                permute(a, l+1, r);
                swap(a[l], a[i]);
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        permute(nums, 0, nums.size());
        
        return ans;
    }
};