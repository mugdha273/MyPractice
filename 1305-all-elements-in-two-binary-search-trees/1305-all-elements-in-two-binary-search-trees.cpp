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

//do an Inorder traversal in both arrays, take two vectors and use the concept of sort two sorted arrays.

class Solution {
public:
    
    vector<int>t;
    
//     void helper(vector<int>v1, vector<int>v2, int m, int n)
//     {
//         int i=0, j=0;
        
//         while(i<m && j<n)
//         {
//             if(v1[i]<v2[j])
//             {
//                 ans.push_back(v1[i++]);
//             }
//             else
//             {
//                 ans.push_back(v2[j++]);
//             }
//         }
//         while(i<m)  ans.push_back(v1[i++]);
//         while(j<n)  ans.push_back(v2[j++]);
        
//     }

    void inorder(TreeNode* root)
    {
        if(root==NULL) return;
        inorder(root->left);
        t.push_back(root->val);
        inorder(root->right);
        
        return;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
//         vector<int>v1;
        inorder(root1);
//         vector<int>v2;
        
        inorder(root2);
        sort(t.begin(), t.end());
//         for(auto x: v1) cout<<x<<" ";
//         cout<<endl;
//         for(auto x: v2) cout<<x<<" ";
//         cout<<endl;
        
//         helper(v1,v2, v1.size(), v2.size());
        return t;
    }
};