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