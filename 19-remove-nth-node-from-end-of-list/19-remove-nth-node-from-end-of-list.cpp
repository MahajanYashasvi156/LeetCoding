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
    ListNode* removeNthFromEnd(ListNode* A, int B) 
    {
          int n = 0;
           ListNode* curr = A;
           while(curr!=NULL)
           {
               curr = curr->next;
               n++;
           }
           int k = n-B;
           if(k==0)
                return A->next;

           curr = A;
           while(curr!=NULL)
           {
               k--;
               if(k==0)
               {
                   curr->next = curr->next->next;
                   return A;
               }
               curr = curr->next;
           }
           return A;
    }
};