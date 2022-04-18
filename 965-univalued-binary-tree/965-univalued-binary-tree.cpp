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
    set<int>s;
    
    void helper(TreeNode* root)
    {
        if(root==NULL) return;
        
        s.insert(root->val);
        helper(root->right);
        helper(root->left);
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        
        helper(root);
        
        if(s.size()==1) return true;
        return false;
        
    }
};