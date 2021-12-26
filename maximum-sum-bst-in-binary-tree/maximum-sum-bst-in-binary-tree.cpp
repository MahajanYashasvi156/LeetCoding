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
class MaxMinSum
{
            
    public:
            int maxval;
            int minval;
            int maxsum;
            MaxMinSum(int maxval,int minval,int maxsum)
            {
                this->maxval=maxval;
                this->minval=minval;
                this->maxsum=maxsum;
            }
};
class Solution 
{
    private :
            int ans=0;
    public:
    
        MaxMinSum* maxSumBSTUtility(TreeNode* root)
        {
            if(root==NULL)
                return new MaxMinSum(INT_MIN,INT_MAX,0);
            
            MaxMinSum* leftRes=maxSumBSTUtility(root->left);
            MaxMinSum* rightRes=maxSumBSTUtility(root->right);
            
            if(leftRes->maxval<root->val and root->val<rightRes->minval)
            {
                ans=max(ans,leftRes->maxsum+rightRes->maxsum+root->val);
                
                return new MaxMinSum(max(root->val,rightRes->maxval),min(root->val,leftRes->minval),leftRes->maxsum+rightRes->maxsum+root->val);
    
            }
            return new MaxMinSum(INT_MAX,INT_MIN,max(leftRes->maxsum,rightRes->maxsum));
        }
        int maxSumBST(TreeNode* root) 
        {
            MaxMinSum* res=maxSumBSTUtility(root);
            return ans;
        }
};