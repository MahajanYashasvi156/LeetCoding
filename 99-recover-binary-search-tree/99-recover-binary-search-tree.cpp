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
        TreeNode* swap2 = NULL;
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
                    swap2 = node;
            }
            node = node->right;
        }
        if(swap1!=NULL and swap2!=NULL)
        {
            int temp = swap1->val;
            swap1->val = swap2->val;
            swap2->val = temp;
        }
        
        
    }
};