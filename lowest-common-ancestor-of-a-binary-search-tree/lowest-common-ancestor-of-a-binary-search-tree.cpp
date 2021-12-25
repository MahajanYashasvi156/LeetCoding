//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/

    /*
        Intuition - 
        If both nodes are on left subtree then go to left subtree
        else If both nodes are on right subtree then go to right subtree
        else If both nodes are on different side of root then root is our LCA
        (If both nodes are on diffrent side then current node will be the ancestor node. )
    
    Approach 1 Recursive-

    TC - O(N) SC O(1) Aux Space O(N)
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        
        if(p->val <root->val and q->val<root->val) 
            return lowestCommonAncestor(root->left,p,q);
        if(p->val >root->val and q->val>root->val) 
            return lowestCommonAncestor(root->right,p,q);
        return root;
            
        
    }
    Approach 2- Recursive 
    TC - O(N) SC O(1) Aux Space O(N)
    */

    class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* curr=root;
        while(curr)
        {
            if(p->val <curr->val and q->val<curr->val) 
                curr=curr->left;
            else if(p->val >curr->val and q->val>curr->val)
                curr=curr->right;
            else
                return curr;
        }
        return curr;
    }
    
    
};


