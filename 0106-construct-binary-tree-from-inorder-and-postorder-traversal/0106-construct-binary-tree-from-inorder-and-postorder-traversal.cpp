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
Recursive - 
TC- O(N)
SC - O(N)
AUX SC- O(N)
*/
class Solution 
{
public:
    TreeNode* buildTreeUtility(vector<int>& postorder,vector<int>& inorder,unordered_map<int,int> &indexInorder,int low,int high,int &postorderIndex)
        //postorderIndex is call by refrence as after left call preorderIndex should be updated depending upon the left subtree nodes and now it tells the index of the nodes that are in the rightsubtree.
    {
        //Invalid Case when there will be no node in the range of inorder traversal
        if(high<low)
            return NULL;
        
        TreeNode* newNode=new TreeNode(postorder[postorderIndex]);
        
        int rootIndex = indexInorder[postorder[postorderIndex]] ;
        postorderIndex--;
        
        //In Postorder Traversal (LRN) we are iterating from last so before Node there will be right subtree so call Right subtree first.
        newNode ->right = buildTreeUtility( postorder,inorder,indexInorder,rootIndex+1,high,postorderIndex);
        newNode ->left  = buildTreeUtility( postorder,inorder,indexInorder,low,rootIndex-1,postorderIndex);
       
        
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int,int> indexInorder;
        int postorderIndex=postorder.size()-1;
        
        for(int i=0;i<inorder.size();i++)
            indexInorder[inorder[i]]=i;
     
        return buildTreeUtility( postorder,inorder,indexInorder,0,inorder.size()-1,postorderIndex);
    }
};