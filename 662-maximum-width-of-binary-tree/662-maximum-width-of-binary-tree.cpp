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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)return 0;
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 1});
        
        int width = 0;
        while (q.size() != 0) {
            unsigned long long int left = q.front().second, right = 0;
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                pair<TreeNode*, unsigned long long int> node = q.front();
                q.pop();
                right = node.second;
                if (node.first->left) {
                    q.push({node.first->left, 2 * node.second });
                }
                if (node.first->right) {
                    q.push({node.first->right, 2 * node.second + 1});
                }
            }
            width = max(width, int(right - left + 1));
        }
        return width;
        
    }
};