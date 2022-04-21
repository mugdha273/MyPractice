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
    
    vector<int>ans;
    void inorder(TreeNode* root)
    {
        if(root==NULL) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* helper(vector<int>& nums, int l, int r)
    {
        if(l>r) return NULL;
        
        int mid = l+(r-l)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums,l, mid-1);
        root->right = helper(nums, mid+1, r);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        
        return helper(ans,0, ans.size()-1);
    }
};