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
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(head->next == NULL)
            return NULL;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast and fast->next)
        {
            if(prev)
                prev = prev->next;
            else
                prev = fast;
            fast = fast->next->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};
