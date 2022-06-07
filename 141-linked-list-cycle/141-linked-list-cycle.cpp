/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Intuition - There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer

Our approach - 
Slow pointer will jump 1 step and fast pointer will jump 2 step
If there is a cycle then it is guarenteed that both these pointers meet each other.
Hence we can use this to solve our problem

Time Complexity     O(N)
Space Complexity    O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
};