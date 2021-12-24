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
class Solution {
public:
    bool check(TreeNode* leftNode, TreeNode* rightNode)
    {
        if(!leftNode and !rightNode)
            return true;
        
        if(leftNode and rightNode and leftNode->val == rightNode->val)
            return check(leftNode->left,rightNode->right) and check(leftNode->right,rightNode->left);
        
        return false; 
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL or (!root->left and !root->right))
            return true;
        return check(root->left,root->right);
        
    }
};