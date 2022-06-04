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
    
   ListNode* rev(ListNode* head)
   {
       ListNode* curr= head;
       ListNode* prev=NULL;
       ListNode* n =NULL;
       
       while(curr!=NULL)
       {
           n = curr->next;
           curr->next=prev;
           prev= curr;
           curr=n;
       }
       return prev;
   }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode newHead(0);
        ListNode* res = &newHead;
        l1 = rev(l1);
        l2= rev(l2);
        
        while(c||l1||l2)
        {
            c += (l1?l1->val:0) + (l2?l2->val:0);
            res->next = new ListNode(c%10);
            res = res->next;
            c =c/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        return rev(newHead.next);
    }
};