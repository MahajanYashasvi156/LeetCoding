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
    int solve(TreeNode* &root)
    {
        if(root==NULL)
            return 0;
        
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        root->left = l==1?root->left:NULL;
        root->right = r==1?root->right:NULL;
        
        return l || r || root->val;
    }
public:
    TreeNode* pruneTree(TreeNode* root) 
    {
        
        int ans = solve(root);
        if(ans==0)
            return NULL;
        return root;
    }
};