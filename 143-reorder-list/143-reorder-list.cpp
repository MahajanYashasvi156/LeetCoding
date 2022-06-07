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
    void reorderList(ListNode* A) 
    {
        ListNode* fast = A;
        ListNode* slow = A;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = NULL;
        ListNode* first = NULL;
        second = slow->next;
        slow->next = NULL; //terminating first list.

        ListNode* prev = NULL;
        ListNode* curr = second;
        while(curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        second = prev;
        first = A;
        ListNode* nextFirst = NULL;
        ListNode* nextSecond = NULL;
        while(second)
        {
            nextFirst = first->next;
            nextSecond = second->next;
            first->next = second;
            second->next = nextFirst;
            first = nextFirst;
            second = nextSecond;
        }
    }
};