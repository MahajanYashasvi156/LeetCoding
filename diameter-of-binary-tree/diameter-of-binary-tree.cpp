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
    int  diameterUtility(TreeNode* root,int &diameter)
    {
        if(root==NULL)
            return 0;
        int m=0,n=0;
        if(root->left)
        {
             m=1+diameterUtility(root->left,diameter);
        }
        if(root->right)
            n=1+diameterUtility(root->right,diameter);
        if((m+n)>diameter)
            diameter=m+n;
        return max(m,n);
        
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
       int diameter=0;
     int x= diameterUtility(root,diameter);
        return diameter;
    }
};