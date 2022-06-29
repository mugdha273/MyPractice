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
    
    void insert(TreeNode* &root, int val)
    {
        if(root->left==NULL && root->right==NULL)
        {
            if(val>root->val)
            {
                root->right= new TreeNode(val);
            }
            else root->left= new TreeNode(val);
            return;
        }
        
        if(val<root->val)
        {
            if(root->left)insert(root->left,val);
            else{
                root->left= new TreeNode(val);
                return;
            }
        }
            
        if(val>root->val)
            {
            if(root->right)insert(root->right,val);
            else{
                root->right= new TreeNode(val);
                return;
            }
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        
        insert(root,val);
        
        return root;
    }
};