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
class Solution {
public:
    void recoverTree(TreeNode* root) 
    {
        TreeNode* curr = root;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL; 
        
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* temp = curr->left;
                
                while(temp->right and temp->right!=curr)
                {
                    temp = temp->right;
                }
                if(temp->right==curr)
                {
                    temp->right = NULL;
                    if(prev and prev->val>curr->val)
                    {
                        if(first==NULL)
                            first = prev;
                        second = curr;
                    }
                   
                    prev = curr;
                    curr = curr->right;
                }
                else
                {
                    temp->right = curr;
                    curr = curr->left;
                } 
            }
            else 
            {
                if(prev and prev->val>curr->val)
                {
                    if(first==NULL)
                        first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
        swap(first->val,second->val);
    }
};







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

TC - O(2N+NLogn)
SC - O(2N)


class Solution 
{
public:
    void recoverTree(TreeNode* root) 
    {
        vector<int> inorderTraversal;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(!s.empty() or node!=NULL)
        {
            while(node)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            inorderTraversal.push_back(node->val);
            node = node->right;
        }
        
        sort(inorderTraversal.begin(),inorderTraversal.end());
        
        node = root;
        int i=0;
        TreeNode* swap1 = NULL;
        while(!s.empty() or node!=NULL)
        {
            while(node)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            if(node->val != inorderTraversal[i++])
            {
                if(swap1==NULL)
                    swap1 = node;
                else 
                {
                    swap(swap1->val,node->val);
                    return;
                } 
            }
            node = node->right;
        } 
    }
};
*/

/*
TC - O(N)
SC - O(N)

class Solution 
{
    
public:
    void recoverTree(TreeNode* root) 
    {
        TreeNode* first = NULL;
        TreeNode* prev = NULL;
        TreeNode* last = NULL;
        
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(!s.empty() or node!=NULL)
        {
            while(node)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            if(prev!=NULL and node->val<prev->val)
            {
                if(first==NULL)
                    first = prev;
                last = node;
            }
            prev = node;
            node = node->right;
        }
        swap(first->val,last->val);
    }
};
*/
/*
class Solution 
{
public:
    void recoverTree(TreeNode* root) 
    {
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* last = NULL;
        
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* temp = curr->left;
                while(temp->right)
                {
                    temp = temp->right;
                }
                temp->right = curr;
                temp = curr->left;
                curr->left = NULL;
                curr = temp;
            }
            else
            {
                if(prev!=NULL and prev->val>curr->val)
                {
                    if(first==NULL)
                    {
                        first = prev;
                    }
                    last = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
        swap(first->val,last->val);
    }
};
*/