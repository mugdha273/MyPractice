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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev= NULL;
        ListNode* n = NULL;
            
            while(curr!=NULL)
            {
                n = curr->next;
                curr->next = prev;
                prev= curr;
                curr= n;
            }
        
        return prev;
        
    }
    
    ListNode* partition(ListNode* head, int x) {
        ListNode newHead(0);
        ListNode*res = &newHead;
        
        stack<int>st1;
        stack<int>st2;
        ListNode* temp= head;
        
        while(temp!=NULL)
        {
            if(temp->val<x) st2.push(temp->val);
            else st1.push(temp->val);
            temp =temp->next;
        }
        while(st1.size()>0)
        {
            res->next = new ListNode(st1.top());
            res=res->next;
            st1.pop();
        }
        while(st2.size()>0)
        {
            res->next = new ListNode(st2.top());
            res=res->next;
            st2.pop();
        }
        
        return reverseList(newHead.next);
    }
};