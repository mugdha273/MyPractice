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
    vector<int>vec;
    
    void helper(TreeNode* root, int level)
    {
        if(root==NULL) return;
        if(level==vec.size())
            vec.push_back(root->val);
        helper(root->right, level+1);
        helper(root->left,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        helper(root,0);
        return vec;
    }
};