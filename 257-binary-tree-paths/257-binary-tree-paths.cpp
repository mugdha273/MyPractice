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
    vector<string>ans;
    void helper(TreeNode* root, string curr)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->right ==NULL && root->left==NULL)
        {
            curr+= to_string(root->val);
            ans.push_back(curr);
        }
        curr += to_string(root->val)+"->";
        helper(root->left, curr);
        helper(root->right, curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string curr="";
        helper(root, curr);
        
        return ans;
        
    }
};