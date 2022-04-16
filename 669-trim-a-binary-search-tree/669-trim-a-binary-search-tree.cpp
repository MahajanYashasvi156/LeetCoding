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
SC - O(1)
ASC - O(n)

Approach - 
if the root values is less than the low value then trimmed tree lies in the right subtree of BST.
if the root values is greate than the high value then trimmed tree lies in the light subtree of BST.
if the root value lies in the range then it will be the root of the trimmed tree. 

LINK - https://www.youtube.com/watch?v=JNAqFV9AgVc
LEETCODE - https://leetcode.com/problems/trim-a-binary-search-tree/submissions/
*/
class Solution 
{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if(root==NULL)
            return root;
        else if(root->val<low)
            return trimBST(root->right,low,high);
        else if(root->val>high)
            return trimBST(root->left,low,high);
        
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        
        return root;
        
    }
};