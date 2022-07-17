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
    
    bool isLeaf(TreeNode* root)
    {
        if(root->left==NULL&&root->right==NULL) return true;
        
        return false;
    }
    
    void storeLeaves(TreeNode* root, vector<int>&v)
    {
        if(root==NULL) return;
        
        if(isLeaf(root)) v.push_back(root->val);
        storeLeaves(root->left,v);
        storeLeaves(root->right,v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        vector<int>v1;
        vector<int>v2;
        storeLeaves(root1,v1);
        storeLeaves(root2,v2);
        return v1==v2;
    }
};