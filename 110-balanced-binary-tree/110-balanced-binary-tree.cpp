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
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        return max(height(root->left), height(root->right))+1;
    }
    vector<pair<int,int>>vec;
    
    void helper(TreeNode* root)
    {
        if(root==NULL) return;
        vec.push_back({height(root->left), height(root->right)});
        isBalanced(root->left);
        isBalanced(root->right);
        
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        helper(root);
        for(auto x:vec){
            // cout<<x.first<<" "<<x.second<<endl;
            if(abs(x.first-x.second)>1) return false;
        }
        return true;
    }
};