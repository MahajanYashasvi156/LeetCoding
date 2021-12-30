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
    void dfs(TreeNode* root,int maxParent,int &count)
    {
        if(root==NULL)
            return;
        if(root->val>=maxParent)
        {
            count++;
            maxParent=root->val;
        } 
        dfs(root->left,maxParent,count);
        dfs(root->right,maxParent,count);
    }
    int goodNodes(TreeNode* root) 
    {
        int count=0;
        int maxParent=INT_MIN;
        dfs(root,maxParent,count);
        return count;
        
    }
};