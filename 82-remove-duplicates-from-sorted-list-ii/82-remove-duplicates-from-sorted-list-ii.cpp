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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp =new ListNode(0);
        ListNode* new_head =temp;
        ListNode* node= head;
        
        
        
        while(node)
        {
            if(node->next && node->val == node->next->val)
            {
                 while (node->next && node->val == node->next->val)
                    node = node->next;
            }
            else {
                temp->next = node;
                temp = node;
            }
            node= node->next;
            
        }
        
        temp->next= NULL;
        
        return new_head->next;
    }
};