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
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* A) 
    {
        if(A==NULL or A->next==NULL)
        return A;
    
        ListNode* tail = NULL;
        ListNode* curr = A;
        ListNode* head = NULL;
        while(curr)
        {
            bool flag = false;
            while(curr->next and curr->val==curr->next->val)
            {
                flag = true;
                curr = curr->next;
            }
            if(flag == false)
            {
                if(head==NULL)
                    head = curr;
                else
                    tail->next= curr;

                tail = curr;
            }
            curr = curr->next;
        }
        if(tail)
            tail->next = NULL;
        return head;
        
    }
};