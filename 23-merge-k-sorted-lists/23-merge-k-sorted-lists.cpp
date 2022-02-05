/*
link - https://leetcode.com/problems/merge-k-sorted-lists/
TC - O(KlogK + K*L*logK) = O(K*L*logK)
SC - O(K)
*/

typedef pair<int,ListNode*> pi;

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        int k = lists.size();
        for(int i=0;i<k;i++)
        {
            if(lists[i])
                pq.push({lists[i]->val,lists[i]});
        }
        ListNode* sortedList = NULL;
        ListNode* head=NULL;
        ListNode* nextNode = NULL;
        while(!pq.empty())
        {
            if(head==NULL)
            {
                head = pq.top().second;
                sortedList= head;
            }
            else
            {
                sortedList->next= pq.top().second;
                sortedList= sortedList->next;
            }
            nextNode = pq.top().second->next;
            pq.pop();
            if(nextNode)
                pq.push({nextNode->val,nextNode});
        }
        return head;
    }
    
};