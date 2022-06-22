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
/* Recursive 

//https://leetcode.com/problems/binary-tree-postorder-traversal/
//SC- O(1) ASC-O(N)
//TC- O(N)

class Solution {
public:
    void preorder(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
          return ;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
      
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        preorder(root,res); 
        return res;
    }
};

class Solution {
public:
    
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) 
    {
      if(root==NULL)
          return res;
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
        
          
    }
};

//Iterative -
//SC- O(N)
//TC- O(N)


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> st;
        TreeNode* curr;
        st.push(root);
        while(!st.empty())
        {
            curr=st.top();
            res.push_back(curr->val);
            st.pop();
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
        }
        return res;
    }
};
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
         vector<int> res;
         stack<TreeNode*> st;
         TreeNode* node=root;
        while(node!=NULL or !st.empty())
        {
            while(node)
            {
                res.push_back(node->val);
                st.push(node);
                node=node->left;
            }
            node=st.top();
            st.pop();
            node=node->right; 
        }
        return res;
    }
};