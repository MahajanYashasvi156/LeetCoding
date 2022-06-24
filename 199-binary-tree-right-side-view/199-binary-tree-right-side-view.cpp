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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root==NULL) return {};
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr = NULL;

        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                   q.push(curr->right);
            }
            result.push_back(curr->val);
        }

        return result;
    }
};

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

//https://leetcode.com/problems/binary-tree-right-side-view/submissions/
/*
TC- O(N)
ASC - O(Height) 
SC- O(1)

class Solution {
public:
    void rightViewUtility(TreeNode *root, vector<int> & res,int &max_level,int curr_level)
{
    if(root==NULL) return;
    if(curr_level>max_level)
    {
        res.push_back(root->val);
        max_level=curr_level;
    }
    rightViewUtility(root->right,res,max_level,curr_level+1);     rightViewUtility(root->left,res,max_level,curr_level+1);
}


    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        int max_level=-1;
        int curr_level=0;
        if(root==NULL) return res;
        rightViewUtility(root,res,max_level,curr_level);

        return res;
    }
};
*/