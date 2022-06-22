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
    TreeNode* mergeTrees(TreeNode* A, TreeNode* B) 
    {
        if(A==NULL)
            return B;
        if(B==NULL)
            return A;

        A->val = A->val+B->val;
        A->left = mergeTrees(A->left,B->left);
        A->right = mergeTrees(A->right,B->right);
        return A;
    }
};