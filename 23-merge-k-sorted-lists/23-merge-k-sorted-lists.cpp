/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b)
    {
        if(a==NULL) return b;
        if(b==NULL) return a;
        
        if(a->val<b->val)
        {
            a->next =merge(a->next, b);
            return a;
        }
        else
        {
            b->next= merge(a, b->next);
            return b;
        }
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if (lists.size() == 0) return NULL;
        int n= lists.size();
        ListNode* l1= lists[0];
        
        for(int i=1; i<n; i++)
        {
            l1= merge(l1, lists[i]);
        }
        
        return l1;
    }
};