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
//**********************************NOICEEE SOLUTION BRO!!*************************************
class Solution {
public:
    TreeNode* trimleft(TreeNode* root, int low)
    {
        if(root == nullptr) return NULL;
        if(root->val<low) return trimleft(root->right, low);
        else root->left=trimleft(root->left, low);
        return root;
    }
    TreeNode* trimright(TreeNode* root, int high)
    {
        if(root == nullptr) return NULL;
        if(root->val>high) return trimright(root->left, high);
        else root->right= trimright(root->right, high);
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root = trimleft(root, low);
        root = trimright(root, high);
        return root;
        
    }
};