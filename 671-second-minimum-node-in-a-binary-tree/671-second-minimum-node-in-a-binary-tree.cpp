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
        helper(root->left);
        s.insert(root->val);
        helper(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        helper(root);
        int cnt=0;
        
        for (auto it:s)
        {
            cnt++;
            if(cnt==2)
            {
                return it;
            }
        }
        return -1;
    }
};