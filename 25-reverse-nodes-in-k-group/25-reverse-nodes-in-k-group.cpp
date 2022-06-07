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
    ListNode* reverseKGroup(ListNode* A, int B) 
    {
        ListNode* first = A;
        int node = 0;
        ListNode* curr = A;
        ListNode* prevTail = NULL;
        ListNode* nextNode = NULL;
        ListNode* head = NULL;
        
        while(curr)
        {
            int i = 0;
            first = curr;
            while(first and i<B)
            { 
                first = first->next;
                i++;
            }
            if(i<B)
                break;

            ListNode* nextListTail = curr;
            ListNode* prev = NULL;
            node = 0;

            while(curr and node<B)
            {
                nextNode =  curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                node++;     
            }
          
            if(prevTail)
                prevTail->next = prev;
            if(head==NULL)
                head = prev;
            prevTail = nextListTail;
        }
        prevTail->next = curr;
        return head;
    }
};

