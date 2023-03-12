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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    ListNode* findMiddle(ListNode*start,ListNode*end)
    {
        ListNode* slow = start;
        ListNode* fast = start;

        while(fast!=end and fast->next!=end)
        {
            slow = slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    TreeNode* BuildTree(ListNode* start,ListNode* end)
    {
        if(start==end)
            return NULL;

        ListNode* middleNode = findMiddle(start,end);
        TreeNode* root = new TreeNode(middleNode->val);
        root->left = BuildTree(start,middleNode);
        root->right = BuildTree(middleNode->next,end);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        return BuildTree(head,NULL);
    }
};