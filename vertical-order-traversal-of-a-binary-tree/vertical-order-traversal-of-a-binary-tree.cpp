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
        void dfs(TreeNode* root,map<int,vector<pair<int,int>>>&mp,int row,int col)
        {
            if(root==NULL)
                return;
            mp[col].push_back({row,root->val});
            dfs(root->left,mp,row+1,col-1);
            dfs(root->right,mp,row+1,col+1);
        }
        vector<vector<int>> verticalTraversal(TreeNode* root) 
        {
            map<int,vector<pair<int,int>>> mp;
            vector<vector<int>> result;
            dfs(root,mp,0,0);
            for(auto a:mp)
            {
                vector<int> temp;
                sort(a.second.begin(),a.second.end());
                for(auto ele:a.second)
                    temp.push_back(ele.second);
                result.push_back(temp);
            }
            return result;
        }
};