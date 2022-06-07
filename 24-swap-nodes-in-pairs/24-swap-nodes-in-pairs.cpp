/*
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        // if head is NULL OR just having a single node, then no need to change anything 
        if(head == NULL || head -> next == NULL) 
        {
            return head;
        }
            
        ListNode* temp; // temporary pointer to store head -> next
        temp = head->next; // give temp what he want
        
        head->next = swapPairs(head->next->next); // changing links
        temp->next = head; // put temp -> next to head
        
        return temp; // now after changing links, temp act as our head
    }
};
*/
/*
class Solution 
{
public:
    ListNode* swapPairs(ListNode* A) 
    {
        if(A==NULL or A->next==NULL)
        return A;
    
        ListNode* curr = A;
        ListNode* prev = NULL;
        ListNode* head = NULL;
        while(curr and curr->next)
        {
            ListNode* nextNode = curr->next->next;
            curr->next->next = curr;
            if(prev)
                prev->next = curr->next;
            else
                head = curr->next;
            curr->next = NULL;
            prev = curr;
            curr = nextNode;
        }
        prev->next = curr;
        return head;
    }
};
*/
class Solution 
{
public:
    ListNode* swapPairs(ListNode* A) 
    {
        if(A==NULL or A->next==NULL)
        return A;

        ListNode* prevTail = NULL;
        ListNode* nextListTail = NULL;
        ListNode* prev = NULL;
        ListNode* curr = A;
        ListNode* nextNode = NULL;
        ListNode* head = NULL;

        while(curr and curr->next)
        {
            nextListTail = curr;
            prev = NULL;
            int i = 2;
            while(i--)
            {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            if(prevTail)
            {
                prevTail->next = prev;
            }
            else
            {
                head = prev;
            }
            prevTail = nextListTail;
        }
        prevTail->next = curr;
        return head;
    }
};