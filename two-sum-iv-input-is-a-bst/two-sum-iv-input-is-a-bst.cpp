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
    bool findTarget(TreeNode* root, int k) 
    {
        map<int,int> mp;
        TreeNode* curr=root;
        stack<TreeNode*> s;
        int rem;
        while(curr or !s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            rem=k-curr->val;
            if(mp.find(rem)!=mp.end())
                return true;
            mp[curr->val]++;
            curr=curr->right;
        }
        
        return false;
    }
};