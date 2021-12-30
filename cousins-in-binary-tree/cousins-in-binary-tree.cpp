class Solution 
{
    public:
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        queue<TreeNode*> levelQueue;
        TreeNode* curr=NULL;
        levelQueue.push(root);
        bool xFound=false;
        bool yFound=false;
        while(!levelQueue.empty())
        {
            int numOfNodesAtLevel=levelQueue.size();
            while(numOfNodesAtLevel--)
            {
                curr=levelQueue.front();
                levelQueue.pop();
                if(curr->left)
                    levelQueue.push(curr->left);
                if(curr->right)
                    levelQueue.push(curr->right);
                if(curr->left and curr->right)
                    if((curr->left->val==x and curr->right->val==y) or (curr->left->val==y and curr->right->val==x))
                    return false;
                if(curr->val==x)
                    xFound=true;
                 if(curr->val==y)
                    yFound=true;
            }
            if(xFound and yFound)
                return true;
            if(xFound or yFound)
                return false;
        }
        return false;
    }
};