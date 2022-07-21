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
    int length(ListNode* head)
    {
        ListNode* temp= head;
        int l=0; 
        while(temp!=NULL){
            l++;
            temp= temp->next;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // cout<<length(head)<<endl;
        int fs= length(head)-n;
        // cout<<fs<<endl;
        if(fs==0) return head->next;
        ListNode* temp= head;
        if(n==0){
            while(temp->next->next!=NULL)
            {
                temp->next=NULL;
            }
            return head;
        }
        while(fs>1 && temp!=NULL)
        {
            // cout<<temp->val<<" ";
            temp=temp->next;
            fs--;
        }
        temp->next= temp->next->next;
        return head;
    }
};