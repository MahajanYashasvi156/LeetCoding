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
class Solution {
public:
    vector<int> values;
    Solution(ListNode* head) 
    {
        ListNode* Node = head;
        while(Node)
        {
            values.push_back(Node->val);
            Node = Node->next;
        }
    }
    
    int getRandom() 
    {
        int n = values.size();
        int index = rand()%n;
        return values[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */