class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* A, ListNode* B) 
    {
        ListNode* num1 = A;
        ListNode* num2 = B;
        ListNode* tail = NULL;
        int carry = 0;
        while(num1 or num2)
        {
            int x = num1 ? num1->val:0;
            int y = num2 ? num2->val:0;
            int sum = (x+y+carry)%10;
            carry = (x+y+carry)/10;
            
            if(num1)
            {
                num1->val = sum;
                if(tail)
                    tail->next = num1;
                tail = num1;
            }
            else
            {
                num2->val = sum;
                if(tail)
                    tail->next = num2;
                tail = num2;
            }
            cout<<tail->val;
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
        return A;
    }
};