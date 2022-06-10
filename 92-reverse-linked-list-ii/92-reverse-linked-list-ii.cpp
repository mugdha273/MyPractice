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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if (!head || !head->next || !m) {
        return head;
    }
        
        ListNode* dummy= new ListNode(0);
        ListNode* it= dummy;
        it->next= head;
        
        for(int i=0; i<m-1; i++)
        {
            it=it->next;
        }
        
        // cout<<it->val;
        
        ListNode* front = it;            
        ListNode* last = it->next; 
        
        ListNode* prev = NULL, *cur = it->next, *next = NULL;
    for (int i = m; i <= n; ++i) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
        
        front->next = prev;
        last->next= cur;
        
        return dummy->next;
    }
};