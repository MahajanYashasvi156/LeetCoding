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
    ListNode* rotateRight(ListNode* A, int B) 
    {
        if(A==NULL)
            return A;
        ListNode* curr = A; 
        int nodes = 1;
        while(curr->next)
        {
            curr= curr->next;
            nodes++;
        }

        ListNode* lastNode = curr;
        B = B%nodes;
        curr = A;
        int nodeNo = nodes-B-1;
        while(nodeNo>0)
        {
            curr = curr->next;
            nodeNo--;
        }
        if(curr->next==NULL)
            return A;
        ListNode* head = curr->next;
        curr->next = NULL;
        lastNode->next = A;
        return head;
        
    }
};