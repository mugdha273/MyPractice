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
    
    int ans;
    
    void helper(TreeNode* root, int &maxDepth,int depth)
    {
        
        if(root==NULL) return;
        
        helper(root->left, maxDepth, depth+1);
        helper(root->right, maxDepth, depth+1);
        
        if(maxDepth<depth)
        {
            maxDepth=depth;
            ans= root->val;
        }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        ans= root->val;
        int leftVal = root->val;
        int maxDepth=0;
        helper(root, maxDepth, 0);
        return ans;
    }
};