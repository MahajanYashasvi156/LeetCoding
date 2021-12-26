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

/*
Link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/

TC- O(N)
SC- O(N)

Intution - Store the traversed(any traversal here we have done inorder traversal) nodes values in the map. If the target number - current value is already present in the map that means pair of two elements whose sum = target number exist in the tree.


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
            if(mp.find(k-curr->val)!=mp.end())
                return true;
            mp[curr->val]=1;
            curr=curr->right;
        }
        return false;
    }
};

*/
/*
Recursive 

TC- O(N)
ASC- O(N)
SC- O(N)
*/
class Solution
{
public:
    map<int,int> mp;
    bool findTarget(TreeNode* root, int k) 
    {
        if(root==NULL)
            return false;
        bool left=findTarget(root->left,k);
        if(left==true)
            return  true;
        if(mp.find(k-root->val)!=mp.end())
            return true;
        mp[root->val]=1;
        return findTarget(root->right,k);
        
    }
};