/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    //All Nodes which are at distance k-dis from the target node.
    void subtreedistanceKNode(TreeNode* root, int dis,int k,vector<int>&res)
    {
        if(root==NULL)
            return;
        if(dis==k)
            res.push_back(root->val);
        subtreedistanceKNode(root->left,dis+1,k,res);
        subtreedistanceKNode(root->right,dis+1,k,res);
    }
    int dfs(TreeNode* root, TreeNode* target,int k,vector<int>&res)
    {
        
        if(root==NULL)
            return -1;
        
        if(root==target)
        {
            subtreedistanceKNode(root,0,k,res);
            return 1;
        } 
        
        int l=dfs(root->left,target,k,res);
        int r=dfs(root->right,target,k,res);
        
        //Means Target is in left subtree.
        if(l!=-1)
        {
            //means current node is at the distance of k
            if(l==k)
                res.push_back(root->val);
            subtreedistanceKNode(root->right,l+1,k,res);
            return l+1;
        } 
        else if(r!=-1)
        {
            //means current node is at the distance of k
            if(r==k)
                res.push_back(root->val);
            subtreedistanceKNode(root->left,r+1,k,res);
            return r+1;
        }
        else
            return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int> res;
        dfs(root,target,k ,res);
        return res;
    }
};