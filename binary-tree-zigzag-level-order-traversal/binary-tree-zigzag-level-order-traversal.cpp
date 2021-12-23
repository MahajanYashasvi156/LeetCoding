/* 
Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/

Iterative-
TC- O(N)
SC- O(N)

Intution - 

Basic Idea - Perform level order traversal at each level.
If the level is odd then reverse the result of that traversal and then push. Else push directly without reversing.

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> levelOrderTraversal;
        
        if(root==NULL) 
            return levelOrderTraversal;
        
        TreeNode* curr;
        
        queue<TreeNode*> q;
        vector<int>levelres;
        int flag=0;
        q.push(root);
        
        while(!q.empty())
        {
            int nodesAtCurrLevel=q.size();
            while(nodesAtCurrLevel--)
            {
                curr=q.front();
                q.pop();
                levelres.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);  
            }
            if(flag==1)
            {
              reverse(levelres.begin(),levelres.end());
              flag=0;
            } 
            else
                flag=1;
            
            levelOrderTraversal.push_back(levelres);
            levelres.clear();
        }
        return levelOrderTraversal;
    }
};
*/

/* Aprroach 2 , Reversal Not Required */

/* 
Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/

Iterative-
TC- O(N)
SC- O(N)

*/
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> levelOrderTraversal;
        
        if(root==NULL) 
            return levelOrderTraversal;
        
        TreeNode* curr;
        
        queue<TreeNode*> q;
        
        int flag=0;
        q.push(root);
        
        while(!q.empty())
        { 
            int nodesAtCurrLevel=q.size();
            vector<int>levelres(nodesAtCurrLevel,0);
            for(int i=0;i<nodesAtCurrLevel;i++)
            {
                curr=q.front();
                q.pop();
                if(flag==1)
                    levelres[nodesAtCurrLevel-1-i]=curr->val;
         
                else
                    levelres[i]=curr->val;
        
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);  
            }
      //Toggling 0 to 1 and 1 to 0, 0 even level, 1 odd level.
            flag=flag^1;
            
            levelOrderTraversal.push_back(levelres);
            levelres.clear();
        }
        return levelOrderTraversal;
    }
};