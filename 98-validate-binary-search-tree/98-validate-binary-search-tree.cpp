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
    bool check(TreeNode* root, long long int l, long long int r)
    {
        if(root==nullptr) return true;
        if(root->val<= l || root->val>= r) return false;
        
        return check(root->left, l, root->val) && check(root->right, root->val, r);
        
    }
    bool isValidBST(TreeNode* root) {  
        return check(root, LONG_MIN, LONG_MAX);
    }
};