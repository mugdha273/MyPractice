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
    void reorderList(ListNode* head) {
        if(head->next!=NULL) 
        {     
        ListNode *slow=head;
        ListNode *fast=head->next;
        

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *curr=slow->next;
        slow->next=NULL;
        

        ListNode *prev=NULL;
        ListNode *nextt=curr->next;
        while(curr!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=nextt;
            if(nextt==NULL)
                continue;
            nextt=nextt->next;
        }
        

        ListNode *temp1=head->next;
        ListNode *temp2=prev->next;
        while(head->next!=NULL && prev->next!=NULL)
        {
            head->next=prev;
            head=temp1;
            temp1=temp1->next;
            
            prev->next=head;
            prev=temp2;
            temp2=temp2->next;
        }
        if(head->next==NULL)
        {
            head->next=prev;
        }
        else
        {
            head->next=prev;
            prev->next=temp1;
        }
        
        }
        
    }
};