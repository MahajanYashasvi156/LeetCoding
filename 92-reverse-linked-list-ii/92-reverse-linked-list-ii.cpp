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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* before = NULL;
        ListNode* last = NULL;
        int node = 1;
        while(node<left)
        {
            prev = curr;
            curr = curr->next;
            node++;
        }
        before = prev;
        last = curr;
        node = left;
        while(node<=right)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            node++;
        }
        if(before)
            before->next = prev;
        else
            head = prev;

        last->next = curr;
        return head;
        
    }
};