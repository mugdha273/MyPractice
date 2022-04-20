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
    unordered_map<TreeNode*, TreeNode*>mp;
    
    void helper(TreeNode* root)
    {
        if(root== NULL) return;
        if(root->left)
        {
            mp[root->left] = root;
            helper(root->left);
        }
        if(root->right)
        {
            mp[root->right] = root;
            helper(root->right);
        }
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        queue<TreeNode*>q;
        unordered_set<int>seen;
        
        q.push(target);
        seen.insert(target->val);
        
        
        int level=0;
        vector<int>ans;
        helper(root);
        
        while(!q.empty())
        {
            int sz= q.size();
            while(sz--)
            {
               if(level==k)
               {
                  while(!q.empty())
                  {
                     ans.push_back(q.front()->val);
                     q.pop(); 
                  }
                   return ans;
               }
                  TreeNode* curr= q.front();
                  q.pop();
                  if(curr->left && seen.find(curr->left->val)==seen.end())
                  {
                      q.push(curr->left);
                      seen.insert(curr->left->val);
                  }
                   if(curr->right && seen.find(curr->right->val)==seen.end())
                  {
                      q.push(curr->right);
                      seen.insert(curr->right->val);
                  }
                  if(mp[curr] && seen.find(mp[curr]->val)==seen.end())
                  {
                      q.push(mp[curr]);
                      seen.insert(mp[curr]->val);
                  }
               
               
                
            }
            level++;
        }
        
        return ans;
    }
};