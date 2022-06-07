/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Time Complexity - O(N)
Space Complexity - O(1)

Concept- 
1. Increase the slow pointer by one node and fast pointer by one node.If there is cycle they will meet at a point.

2. From the node the slow pointer and next pointer meets the distance of intersection/start node of cycle is the same as the distance of start node from the head.

3. Set fast pointer to head node .Now, fast pointer will also increased by one node and increase slow pointer by one node. Since the distance of start node from the head and slow pointer is same both this pointers will meet at start node only(fast pointer traverses the nodes which are not in the cycle, slow pointer now covers nodes which are in the cycle only) 

Thus, Dist(start of cycle, fast slow ptr meet) = Dist(start of cycle, head)

*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                break;
        }
        if(fast==NULL or fast->next==NULL)
            return NULL;
        fast = head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};