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
    ListNode* getMid(ListNode* head)
    {
        ListNode* slow= head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow= slow->next;
            fast= fast->next->next;
            
        }
        
        return slow;
    }
    
    ListNode *reverse(ListNode *head){
		if(!head || !head->next) return head;
		ListNode *curr=head,*prev=nullptr,*next;
		while(curr){
			 next=curr->next;
			 curr->next=prev;
			 prev=curr;
			 curr=next;
		}
		return prev;
	}

    
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        
        ListNode* mid= getMid(head);
        ListNode* head2= mid->next;
        mid->next= NULL;
        
        ListNode* curr2 = reverse(head2);
        ListNode* curr1 = head, *temp1, *temp2;
        
        while(curr1 || curr2) {
            if(curr1) {
                temp1 = curr1->next;
                curr1->next = curr2;
                curr1 = temp1;
            }
            if(curr2) {
                temp2 = curr2->next; 
                curr2->next = temp1;
                curr2 = temp2;
            }
        }


        
        
    }
};