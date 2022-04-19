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

/*

TC - O(2N+NLogn)
SC - O(2N)


class Solution 
{
public:
    void recoverTree(TreeNode* root) 
    {
        vector<int> inorderTraversal;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(!s.empty() or node!=NULL)
        {
            while(node)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            inorderTraversal.push_back(node->val);
            node = node->right;
        }
        
        sort(inorderTraversal.begin(),inorderTraversal.end());
        
        node = root;
        int i=0;
        TreeNode* swap1 = NULL;
        while(!s.empty() or node!=NULL)
        {
            while(node)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            if(node->val != inorderTraversal[i++])
            {
                if(swap1==NULL)
                    swap1 = node;
                else 
                {
                    swap(swap1->val,node->val);
                    return;
                } 
            }
            node = node->right;
        } 
    }
};
*/

/*
TC - O(N)
SC - O(N)
*/
class Solution 
{
    
public:
    void recoverTree(TreeNode* root) 
    {
        TreeNode* first = NULL;
        TreeNode* prev = NULL;
        TreeNode* last = NULL;
        
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(!s.empty() or node!=NULL)
        {
            while(node)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            if(prev!=NULL and node->val<prev->val)
            {
                if(first==NULL)
                    first = prev;
               
                last = node;
            }
            prev = node;
            node = node->right;
        }
        swap(first->val,last->val);
    }
};