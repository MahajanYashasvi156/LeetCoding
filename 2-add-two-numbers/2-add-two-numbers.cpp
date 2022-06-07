class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* A, ListNode* B) 
    {
        ListNode* num1 = A;
        ListNode* num2 = B;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(num1 or num2)
        {
            int x = num1 ? num1->val:0;
            int y = num2 ? num2->val:0;
            int sum = (x+y+carry)%10;
            carry = (x+y+carry)/10;
            ListNode* sumNode = new ListNode(sum);
            if(head==NULL)
                head = sumNode;
            else
                tail->next = sumNode;
            tail = sumNode;
            if(num1)
                num1 = num1->next;
            if(num2)
                num2 = num2->next;
        }
        if(carry)
        {
             ListNode* lastNode = new ListNode(carry);
             tail->next = lastNode;
        }
        return head;
    }
};