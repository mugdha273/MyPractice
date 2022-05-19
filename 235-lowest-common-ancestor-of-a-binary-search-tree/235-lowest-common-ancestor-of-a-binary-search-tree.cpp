/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a=root->val;
        int b=p->val;
        int c=q->val;
        if((a==b)||(a==c))
        {
            return root;
        }
        else if((a>b && a<c)||((a<b && a>c)))
        {
            return root;
            
        }
        else if(a>b && a>c)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(a<b && a<c)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        
       return root;
        
    }
};