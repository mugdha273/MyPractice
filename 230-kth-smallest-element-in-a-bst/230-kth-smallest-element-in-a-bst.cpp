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
    void helper(TreeNode* root, int &lvl)
    {
        if(root==NULL||lvl==0) return;
        helper(root->left,lvl);
        if(lvl==1) ans=root->val;
        lvl--;
        helper(root->right,lvl);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return ans;
    }
};