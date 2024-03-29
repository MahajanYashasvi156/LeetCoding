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

//Approach - Remove a node if its value is same as previous
//TC - O(N) SC - O(1)

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
      ListNode* curr=head;
      ListNode* prev=NULL;
        while(curr)
        {
            if(prev!=NULL and prev->val==curr->val)
            {
               prev->next=curr->next;
               delete(curr);
               curr=prev->next;
            } 

            else
            {
                prev=curr;
                curr=curr->next;    
            }  
        }
        return head;
    }
};