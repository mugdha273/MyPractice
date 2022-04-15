/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode* head)
    {
        int len =0;
        ListNode* temp = head;
        
        while(temp!=nullptr)
        {
            temp= temp->next;
            len++;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(len(headA)>len(headB)) return getIntersectionNode(headB, headA);
        
        int lenA= len(headA);
        int lenB = len(headB);
        
        ListNode* tempA= headA;
        ListNode* tempB= headB;
        
        int diff = lenB-lenA;
        
        while(diff--)
        {
            tempB= tempB->next;
        }
        
        while(tempA!=nullptr)
        {
            if(tempA==tempB) return tempA;
            else{
                tempA= tempA->next;
                tempB =tempB->next;
            }
        }
        
        return tempA;
    }
};