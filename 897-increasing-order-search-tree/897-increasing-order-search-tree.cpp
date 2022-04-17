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
    TreeNode* ans = new TreeNode();
    void dfs(TreeNode* root)
    {
        if(root==NULL) return;
        dfs(root->left);
        ans->right = new TreeNode(root->val);
        ans=ans->right;
        dfs(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp;
        temp = ans;
        dfs(root);
        return temp->right;
        
    }
};