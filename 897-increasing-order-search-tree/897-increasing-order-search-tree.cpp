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
class Solution 
{
    TreeNode* prev = NULL;
    TreeNode* newRoot = NULL;
public:
    TreeNode* increasingBST(TreeNode* root) 
    {
        if(root == NULL) return root;
        increasingBST(root->left);
        if(prev == NULL)
            newRoot = root;
        else 
            prev->right = root;
        
        prev = root; 
        root->left = NULL;
        increasingBST(root->right);
        return newRoot;
    }
};
*/

class Solution 
{
    TreeNode* prev = NULL;
    TreeNode* newRoot = NULL;
public:
    TreeNode* increasingBST(TreeNode* root) 
    {
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(node!=NULL or !s.empty())
        {
            while(node)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            node->left = NULL;
            if(prev == NULL)
                newRoot = node;
            else
                prev->right = node;
            prev = node;
            node= node->right;
        }
        return newRoot;
    }
};