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
    ListNode* partition(ListNode* head, int x) 
    {
        /*headA to tailA maintains list of smaller elements than B*/
        /*headB to tailB maintains list of greater than equal to elements than B*/
        ListNode* headA  = NULL; 
        ListNode* headB = NULL; 
        ListNode* tailA = NULL;
        ListNode* tailB = NULL;
        ListNode* curr = head;

        while(curr!=NULL)
        {
        if(curr->val<x)
        {
            if(headA==NULL)
            {
                headA= curr;
                tailA= curr;
            }
            else
            {
                tailA->next = curr;
                tailA = tailA->next;
            }
            curr=curr->next;
            tailA->next = NULL;
        }
        else
        {
            if(headB==NULL)
            {
                headB= curr;
                tailB= curr;
            }
            else
            {
                tailB->next = curr;
                tailB = tailB->next;
            }

            curr=curr->next;
            tailB->next = NULL;
        }
        }
        if(tailA!=NULL)
        {
        tailA->next = headB;
        return headA;
        }
        return headB;
        
    }
};