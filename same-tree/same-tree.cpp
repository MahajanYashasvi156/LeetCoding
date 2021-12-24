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

class Solution {
public:
    
    //Iterative TC - O(N) SC - O(N) 
    
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        stack<pair<TreeNode*,TreeNode*>> s;
        s.push({p,q});
        while(!s.empty())
        {
            pair<TreeNode*,TreeNode*> nodePointers = s.top();
            s.pop();
            
            if(nodePointers.first==NULL and nodePointers.second==NULL)
                continue;
            
            if(nodePointers.first==NULL or nodePointers.second==NULL)
                return false;
            
            if(nodePointers.first->val != nodePointers.second->val)
                return false;
            
            s.push({nodePointers.first->left,nodePointers.second->left});
            s.push({nodePointers.first->right,nodePointers.second->right});
        }
        return true;
    }
  

    Link - https://leetcode.com/problems/same-tree/
    TC- O(N)
    SC- O(1)
    ASC- O(Height)-O(N)
    
    
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL and q==NULL)
            return true;
        if(p==NULL or q==NULL)
            return false;
        if(p->val!=q->val)
            return false;
        return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }
    }
    */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL)
            return true;
        
        if(p and q and p->val == q->val)
            return isSameTree(p->right,q->right) and isSameTree(p->left,q->left);
        
        return false;
    }
};