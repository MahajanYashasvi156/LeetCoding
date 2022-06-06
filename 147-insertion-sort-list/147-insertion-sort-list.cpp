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
    ListNode* insertionSortList(ListNode* A) 
    {
        ListNode* curr = A->next;
        ListNode* prev = NULL;
        ListNode* it =NULL;
        ListNode* head = A;
        head->next=NULL;
        ListNode* nextNode;
        while(curr!=NULL)
        {
            nextNode = curr->next;
            curr->next = NULL;
            prev = NULL;
            it = head;
            while(it!=NULL and it->val<=curr->val)
            {
                prev = it;
                it=it->next;
            }
            if(prev!=NULL)
            {
                curr->next= prev->next;
                prev->next = curr;
            }
            else
            {
                curr->next= head;
                head = curr;
            }
            curr= nextNode;
        }
        return head;
        
    }
};