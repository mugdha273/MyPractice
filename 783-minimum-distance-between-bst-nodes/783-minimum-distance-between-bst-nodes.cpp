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
    void inorder(TreeNode*root)
    {
        if(root==NULL) return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
        
    }
    
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        int curr=0;
        
        inorder(root);
        
        for(int i=1; i<vec.size(); i++)
        {
            curr = vec[i]-vec[i-1];
            if(curr<ans)
            {
                ans=curr;
            }
        }
        
        return ans;
        
    }
};