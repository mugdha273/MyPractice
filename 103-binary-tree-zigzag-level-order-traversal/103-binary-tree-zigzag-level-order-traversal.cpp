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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)return {};
        queue<TreeNode*>q;
        q.push(root);
        int s=1;
        
        while(!q.empty())
        {
            vector<int>level;
            int sz = q.size();
            
            for(int i=0; i<sz; i++)
            {
                TreeNode* node= q.front();
                q.pop();
                if(node->right)q.push(node->right);
                if(node->left)q.push(node->left);
                level.push_back(node->val);
            }
            if(s%2==0)
            {
                ans.push_back(level);
            }
            else
            {
                reverse(level.begin(), level.end());
                ans.push_back(level);
            }
            s++;
        }
        
        
        return ans;
        
    }
};