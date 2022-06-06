/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
            cout<<list1[i];
            i--;
            j--;
        }
        return intersectNode;
    }
};