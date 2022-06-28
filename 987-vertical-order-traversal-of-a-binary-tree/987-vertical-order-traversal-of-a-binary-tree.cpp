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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>vec;
        if(root==NULL) return vec;
        
        vector<int>store;
        
//         if(root->right==NULL && root->left==NULL)
//         {
//             store.push_back(root->val);
//              vec.push_back(store);
//             return vec;
//         }
        vector<pair<pair<int,int>,int>>s;
        
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            int sz= q.size();
            
            for(int i=0;i<sz; i++)
            {
                TreeNode* node= q.front().first;
                pair<int,int>p= q.front().second;
                q.pop();
                
                if (node->left) {
                    q.push({node->left, {p.first+1, p.second-1}});
                }
                if (node->right) {
                    q.push({node->right, {p.first+1, p.second+1}});
                }
                s.push_back({{p.second,p.first},node->val});
            }
            
        }
        sort(s.begin(), s.end());
        
        
        map<int,vector<int>>mp;
        
        for(auto x:s)
        {
            mp[x.first.first].push_back(x.second);
        }
        
        for(auto x:mp)
        {
            vec.push_back(x.second);
        }
        
        return vec;
    }
};