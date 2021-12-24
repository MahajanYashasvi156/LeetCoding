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
Link - https://leetcode.com/problems/path-sum/submissions/
TC- O(N)
AUX SC- O(N)
SC- O(1)

If left or right subtree have remainder target Sum(Actual targetSum - root value) then target sum is present
If node is leaf node and the target sum reminder is found as leaf's value 
then we got the target sum in the tree
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL)
            return false;
        
       if(root->left==NULL and root->right==NULL)
       {
           if(targetSum==root->val)
               return true;
           return false;
       }
        return hasPathSum(root->left,targetSum-root->val) or hasPathSum(root->right,targetSum-root->val);
    }
};