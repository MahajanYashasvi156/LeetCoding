/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
https://www.interviewbit.com/problems/nodes-at-distance-k/

Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/
TC - O(N)
SC - O(N)

Algorithm - Traverse every node with a depth first search dfs. We'll add all nodes x to the answer such that node is the node on the path from x to target that is closest to the root.

To help us, dfs(node) will return the distance from node to the target. Then, there are 4 cases:

1.If node == target, then we should add nodes that are distance K in the subtree rooted at target.

2. If target is in the left branch of node, say at distance L+1, then we should look for nodes that are distance K - L - 1 in the right branch.

3. If target is in the right branch of node, the algorithm proceeds similarly.

4. If target isn't in either branch of node, then we stop.

Basically,
Firstly find the target.
Find nodes at distance k in left and right subtree of target.
Return distance 1 to parent of target (as target is at distance 1 from parent), so now parent can search in its other subtree than target at actual distance(k) - distance returned from its other child.
*/
class Solution 
{
public:
    //Add all nodes which are at distance k-dis from the target node.
    void subtreedistanceKNode(TreeNode* root, int dis,int k,vector<int>&res)
    {
        if(root==NULL)
            return;
        if(dis==k)
            res.push_back(root->val);
        subtreedistanceKNode(root->left,dis+1,k,res);
        subtreedistanceKNode(root->right,dis+1,k,res);
    }
    
    // Return vertex distance from node to target if exists, else -1
    // Vertex distance: the number of vertices on the path from node to target.
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
        //Means Target is in left subtree.
        if(l!=-1)
        {
            //Means current node is at the distance of k so no need to go to right subtree.
            if(l==k)
            {
                res.push_back(root->val);
                return l+1;
            }
            subtreedistanceKNode(root->right,l+1,k,res);
            return l+1;
        } 
        int r=dfs(root->right,target,k,res);
        
        //Means Target is in right subtree.
        if(r!=-1)
        {
            //Means current node is at the distance of k so no need to go to left subtree.
            if(r==k)
            {
                 res.push_back(root->val);
                 return r+1;
            } 
            subtreedistanceKNode(root->left,r+1,k,res);
            return r+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int> res;
        dfs(root,target,k ,res);
        return res;
    }
};