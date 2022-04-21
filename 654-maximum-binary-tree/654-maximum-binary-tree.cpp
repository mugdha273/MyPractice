/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    int getMax(vector<int>& nums, int x, int y)
    {
        if(x<0 || x> nums.size()-1) return -1;
        if(y<0 || y> nums.size()-1) return -1;
        int ans= -1; 
        int r=-1;
        for(int i=x; i<=y; i++)
        {
            if(ans< nums[i])
            {
                ans = nums[i];
                r=i;
            }
        }
        cout<<r<<endl;
        return r;
    }
    
    TreeNode* construct(vector<int>&nums, int l, int r)
    {
        int p = getMax(nums, l, r);
        
        if(p==-1) return NULL;
        
        TreeNode* root = new TreeNode(nums[p]);
        
        root->left = construct(nums, l, p-1);
        root->right = construct(nums, p+1, r);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return construct(nums, 0, nums.size()-1);
    }
};