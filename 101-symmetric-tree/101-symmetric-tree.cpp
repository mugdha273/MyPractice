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
    bool isSameTree(TreeNode* p, TreeNode* q) {
         if (p == NULL || q == NULL) return (p == q);
        return (p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left));
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        return isSameTree(l,r);
    }
};