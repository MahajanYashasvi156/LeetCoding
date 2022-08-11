/*
Link - https://leetcode.com/problems/validate-binary-search-tree/submissions/

Inorder traversal of BST is nothing but sorted order
So let us use that property as follows
Maintain the inorder predecessor, and check if the that node is lesser than current node.
If yes, then good and continue
If not, then return false
*/


/*
Recursive Approach 
TC O(N)
Aux SC O(N)
SC O(1)


class Solution 
{
public:
    TreeNode* prev=NULL;
    
    bool isValidBST(TreeNode* root) 
    {
       if(root==NULL)
           return true;
     
        bool leftValid = isValidBST(root->left);
        if(!leftValid)
            return false;
        
        if(prev and prev->val >= root->val)
           return false;
        
        prev = root;
        
        bool rightValid = isValidBST(root->right);
        return rightValid;
    }
};

Iterative Approach 
TC O(N)
SC O(N)
*/


class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    { 
        stack<TreeNode*> inorderStack;
        
        TreeNode* curr=root;
        TreeNode* prev=NULL;
     
        while(curr or !inorderStack.empty())
        {   
            while(curr)
            {
                inorderStack.push(curr);
                curr=curr->left;
            }
        
            curr=inorderStack.top();
            inorderStack.pop(); 
            
            if(prev and curr->val<=prev->val)
                    return false;
            prev=curr;
            
            curr=curr->right;
            
        }
        return true;
    }
};