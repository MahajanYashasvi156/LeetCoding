/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        if(original == NULL)
            return cloned;
        if(original == target)
            return cloned;
         TreeNode* result=NULL;
         result = getTargetCopy(original->left,cloned->left,target);
        if(result)
            return result;
        result = getTargetCopy(original->right,cloned->right,target);
        return result;
        
    }
};