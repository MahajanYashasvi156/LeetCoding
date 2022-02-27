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

class Solution 
{
public:
    /*
    int widthOfBinaryTree(TreeNode* root) 
    {
        int maxWidth = INT_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int level = 1;
        while(!q.empty())
        {
            int maxIndex = INT_MIN;
            int minIndex = INT_MAX;
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                auto n = q.front();
                q.pop();
                int index = n.second;
                TreeNode* curr = n.first;
                maxIndex = max(maxIndex,index);
                minIndex = min(minIndex,index);
                if(curr->left)
                {
                    q.push({curr->left,(long long)(2*index+1)});
                }
                
                if(curr->right)
                {
                    q.push({curr->right,(long long)(2*index+2)});
                }
            }
            maxWidth = max(maxWidth,abs(maxIndex - minIndex +1));
            level++;
            
        }
        return maxWidth;
    }
    */
    int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});   
    int ans=0;
    while(!q.empty())
    {
      int count=q.size();
      int mx=INT_MIN,mn=INT_MAX;      // in every level finding minimum index and maximum index
      for(int i=0;i<count;i++)
      {
        TreeNode *p=q.front().first;
        int x=q.front().second;
        q.pop();
        mx=max(mx,x);
        mn=min(mn,x);
        if(p->left)
        {
          q.push({p->left,(long long)2*x+1});
        }
        if(p->right)
        {
          q.push({p->right,(long long)2*x+2});
        }
      }
      ans=max(ans,abs(mx-mn+1));          
    }
  return ans; 
}
};