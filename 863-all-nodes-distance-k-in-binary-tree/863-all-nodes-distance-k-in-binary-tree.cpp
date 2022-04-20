/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Approach:
Make tree as graph
push all parents into map (root, its parent) as you can not traverse upward in tree.
Now use level order/ BFS.
for ex, when you are standing at 5, push its right, left and parent(you'll access this using map which you used to store the parents) into queue. this will be your level 1;

now push l (null), r(null), parent(5, already seen) of 6; l(7), r(4), parent(5, already seen); 3's parent(1, not seen), 3's r (1), 3's l (5, already seen); hence this level is completed and value of level is 2; pop now.

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