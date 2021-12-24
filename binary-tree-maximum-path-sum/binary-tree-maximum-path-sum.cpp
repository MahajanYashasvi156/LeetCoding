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
    int check(TreeNode* root,int &maxPath)
    {
        if(root==NULL)
            return 0;
        
        int leftPath=check(root->left,maxPath);
        int rightPath=check(root->right,maxPath);
        
        maxPath=max(maxPath,leftPath+rightPath+root->val);
        
        
        return max(0,root->val+max(leftPath,rightPath));
        
    }
    int maxPathSum(TreeNode* root) 
    {
        int maxPath=INT_MIN;
        check(root, maxPath);
        return maxPath;
    }
};