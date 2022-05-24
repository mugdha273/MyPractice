/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL|| root==p || root==q) return root;
        int a = p->val;
        int b = q->val;
        int c = root->val;
        
        TreeNode* left= lowestCommonAncestor(root->left, p,q);
        TreeNode* right= lowestCommonAncestor(root->right, p,q);
        
        if(!left) return right;
        if(!right) return left;
        
        else return root;
    }
};