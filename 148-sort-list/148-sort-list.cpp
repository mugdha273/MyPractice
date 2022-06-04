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
    ListNode* midpoint(ListNode* head)
    {
        if(head==NULL||head->next==NULL) return head;
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    
    ListNode* helper(ListNode* l1, ListNode* l2)
    {
      if(l1==NULL) return l2;
      if(l2==NULL) return l1;  
      
        if(l1->val<l2->val)
        {
            l1->next = helper(l1->next, l2);
            return l1;
        }
        else{
            l2->next = helper(l1, l2->next);
            return l2;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        ListNode* mid = midpoint(head);
        ListNode*a= head;
        ListNode* b = mid->next;
        
        mid->next = NULL;
        
        a = sortList(a);
        b = sortList(b);
        
        ListNode* temp = helper(a, b);
        return temp;
        
    }
};