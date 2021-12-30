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
    TreeNode* constructBST(vector<int> &preorder,int &index,int bound)
    {
        if(index==preorder.size() or preorder[index]>bound)
            return NULL;
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left  = constructBST(preorder,index,root->val);
        root->right = constructBST(preorder,index,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        int index=0;
        return constructBST(preorder,index,INT_MAX);
    }
};