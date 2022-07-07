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
        vector<TreeNode*> solve(int low,int high,vector<vector<vector<TreeNode*>>>&dp)
    {
        vector<TreeNode*> ans;

        if(low>high)
            return {NULL};

        if(dp[low][high].size()>0)
            return dp[low][high];
        for(int i = low;i<=high;i++)
        {

            auto lft = solve(low,i-1,dp);
            auto rgt = solve(i+1,high,dp);

            for(auto leftRootNode :lft)
            {
                for(auto rightRootNode:rgt)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRootNode;
                    root->right = rightRootNode;
                    ans.push_back(root);
                }
            }
        }
        return dp[low][high]=ans;
    }

public:
    vector<TreeNode*> generateTrees(int A) 
    {
        vector<vector<vector<TreeNode*>>>dp(A+1,vector<vector<TreeNode*>>(A+1));
        return solve(1,A,dp);
        
    }
};