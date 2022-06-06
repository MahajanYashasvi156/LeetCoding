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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* slowPrev=NULL;
        while(fast and fast->next)
        {
            slowPrev=slow;
            slow = slow->next;
            fast = fast->next->next; 
            
        }

        if(slowPrev)
            slowPrev->next=NULL;
        
        if(fast)
            slow=slow->next;
        slow=reverseList(slow); 
        while(head and slow)
        {
            if(head->val!=slow->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};