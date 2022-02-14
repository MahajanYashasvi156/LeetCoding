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
    int maxDepth(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};









/*
//https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/
//TC-  O(N)
//SC- O(1) ASC - O(N)
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int leftTreeDepth=maxDepth(root->left);
        int RightTreeDepth=maxDepth(root->right);
        return 1+max(leftTreeDepth,RightTreeDepth);
    }
};
*/