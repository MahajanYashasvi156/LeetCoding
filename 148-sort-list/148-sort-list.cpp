/*
https://leetcode.com/problems/sort-list/submissions/

MS(head)
    //base case 
    if pointer points to NULL or single node, then return the pointer
    
    1. Find Middle node, along with this divide the original list into two. So one list starting with head and other with mid. For this,just make next ptr of mid's previous node to NULL
    Now we have two lists
    2. sortedFirstList = MS(head) -- fist list
    3. sortedSecondList = MS(mid) -- second list
    4. merger2SortedLists(sortedFirstList,sortedSecondList);

*/

class Solution 
{
    public:
    //https://leetcode.com/problems/merge-two-sorted-lists/submissions/
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* ptr1=list1;
        ListNode* ptr2=list2;
        ListNode* head=NULL;
        ListNode* mergeptr=NULL;
        while(ptr1 and ptr2)
        {
            if(ptr1->val<= ptr2->val)
            {
                if(mergeptr)
                   mergeptr->next=ptr1;
                mergeptr=ptr1;
                ptr1=ptr1->next;
            }
            else            
            {
                if(mergeptr)
                   mergeptr->next=ptr2;
                mergeptr=ptr2;
                ptr2=ptr2->next;
            }
            if(head==NULL)
                head=mergeptr;
        }
        if(ptr1)
        {
           if(mergeptr)
                   mergeptr->next=ptr1;
            mergeptr=ptr1;
            if(head==NULL)
                head=mergeptr;
            
        }
        else if(ptr2)
        {
            if(mergeptr)
                   mergeptr->next=ptr2;
            mergeptr=ptr2;
             if(head==NULL)
                head=mergeptr;
        } 
        return head;
    }
    
    //middle node will return the middle node and sets the previous node's next of the middle to be NULL.Thus it will create two list such that first list head is head and second list head is mid.
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            if(prev==NULL)
                prev=head;
            else
                prev=prev->next;
        }
        ListNode* mid=prev->next;
        prev->next=NULL;
        return mid;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        //Base case if there is only one node or no node in the list.
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode* mid = middleNode(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return mergeTwoLists(left,right);
    }
};