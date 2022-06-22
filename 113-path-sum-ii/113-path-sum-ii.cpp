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
    void solve(TreeNode* root,int targetSum,vector<int> path,vector<vector<int>>&result)
    {
        if(root==NULL)
            return;
        path.push_back(root->val);
        if(root->left==NULL and root->right == NULL and root->val==targetSum)
            result.push_back(path);
        solve(root->left,targetSum-root->val,path,result);
        solve(root->right,targetSum-root->val,path,result);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int> path;
        vector<vector<int>> result;
        solve(root,targetSum,path,result);
        return result;
    }
};