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
/*class Solution {
public:
    TreeNode* invertTree(TreeNode* node) 
    {
        if(node==NULL)
            return NULL;
        swap(node->left,node->right);
        node->left=invertTree(node->left);
        node->right=invertTree(node->right);
        return node;
    }
};*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* node) 
    {
        if(node==NULL)
            return node;
        
        TreeNode* tempr = node->right;
        node->right = invertTree(node->left);
        node->left = invertTree(tempr);
        
        return node;
    }
};