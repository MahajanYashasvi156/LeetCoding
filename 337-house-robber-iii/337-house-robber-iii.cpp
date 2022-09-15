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
    pair<int,int> solve(TreeNode* root)
    {
        if(root==NULL)
            return {0,0};
        
       pair<int,int> leftMoney = solve(root->left);
       pair<int,int> rightMoney = solve(root->right);
        
        return {root->val+leftMoney.second+rightMoney.second , max(leftMoney.first,leftMoney.second)+max(rightMoney.first,rightMoney.second)};
        
    }
public:
    int rob(TreeNode* root) 
    {
        pair<int,int> ans = solve(root);
        
        return max(ans.first,ans.second);
    }
};