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
Similar to identical tree logic, just a difference is we will check left subtree with right subtree and vice versa.

Recursive -

TC      - O(N)
Aux SC  - O(N)
SC      - O(1)
*/
class Solution {
public:
    bool check(TreeNode* leftNode, TreeNode* rightNode)
    {
        if(leftNode==NULL and rightNode==NULL)
            return true;
        
        if(leftNode and rightNode and leftNode->val == rightNode->val)
            return check(leftNode->left,rightNode->right) and check(leftNode->right,rightNode->left);
        
        //When node's values are diffrent or one of the node is NULL.
        return false; 
    }
    bool isSymmetric(TreeNode* root) 
    {
        return check(root->left,root->right);
    }
};