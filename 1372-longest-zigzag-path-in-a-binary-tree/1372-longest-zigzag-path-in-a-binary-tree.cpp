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
    int maxLen;
    void longestZigZag(TreeNode* root, char dir, int len) {
        if(root == nullptr) return;
        
        maxLen = max(maxLen, len);
        
		if(dir == 'l') {
            longestZigZag(root->left, 'l', 1);
            longestZigZag(root->right, 'r', len + 1);
        }
        else {

            longestZigZag(root->right, 'r', 1);
            longestZigZag(root->left, 'l', len + 1);
        }
    }
    
    int longestZigZag(TreeNode* root) {
		maxLen = 0;
        longestZigZag(root->right, 'r', 1);
        longestZigZag(root->left, 'l', 1);
        return maxLen;
    }
};