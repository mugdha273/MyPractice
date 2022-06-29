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
    TreeNode* invert(TreeNode* root)
    {
        if(root==NULL) return root;
        swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
        
        return root;
    }
    bool isSameTree(TreeNode*p ,TreeNode* q)
    {
        if (p == NULL || q == NULL) return (p == q);
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
    bool isSymmetric(TreeNode* root) {
        invert(root->right);
        return isSameTree(root->left, root->right);
    }
};