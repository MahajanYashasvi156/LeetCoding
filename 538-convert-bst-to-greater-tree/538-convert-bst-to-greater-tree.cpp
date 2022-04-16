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
TC - O(n)
SC - O(n)

reverse inorder traversal - Right Node Left

class Solution 
{
public:
    TreeNode* convertBST(TreeNode* root) 
    {
        stack<TreeNode*> st;
        TreeNode* node=root;
        int value = 0;
        
        while(node!=NULL or !st.empty())
        {
            while(node)
            {
                st.push(node);
                node=node->right;
            }
            node=st.top();
            st.top()->val = value + st.top()->val;
            value = st.top()->val;
            st.pop();
            node=node->left; 
        }
        return root;
    }
};
*/

class Solution 
{
    int value = 0;
public:
    TreeNode* convertBST(TreeNode* root) 
    {
        if(root == NULL)
            return root;
        root->right = convertBST(root->right);
        root->val = value + root->val;
        value = root->val;
        root->left = convertBST(root->left);
        return root;
    }
};
