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
    ListNode* removeElements(ListNode* head, int val) {
        
        
        if(head==NULL) return NULL;
        if(head->val==val)
        {
            while(head->val==val && head!=NULL && head->next!=NULL)
            {
                head=head->next;
            }
        }
        ListNode* n = head;
        
        while(n!=NULL && n->next!=NULL)
        {
            if(n->next->val == val)
            {
                n->next = n->next->next;
            }
            else
                n = n->next;
        }
        
        if(n->val==val) return NULL;
        
        return head;
    }
};