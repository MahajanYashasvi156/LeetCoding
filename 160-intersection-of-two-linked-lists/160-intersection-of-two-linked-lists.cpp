/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/2116312/C%2B%2B-oror-Easiest-way-oror-O(1)-space

class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)         {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        while(ptr1!=ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(ptr1==ptr2)
                 break;
            if(ptr1==NULL)
                ptr1=headB;
            if(ptr2==NULL)
                ptr2=headA;
        }
        return ptr1;
    }
};

/*
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        vector<ListNode*> list1;
        vector<ListNode*> list2;
        
        ListNode *temp = headA;
        while(temp!=NULL)
        {
            list1.push_back(temp);
            temp = temp->next;
        }
        
        temp = headB;
        while(temp!=NULL)
        {
            list2.push_back(temp);
            temp = temp->next;
        }
        
        int i = list1.size()-1;
        int j = list2.size()-1;
        ListNode* intersectNode = NULL;
        while(i>=0 and j>=0 and list1[i]==list2[j])
        {
            intersectNode = list1[i];
            i--;
            j--;
        }
        return intersectNode;
    }
};
*/