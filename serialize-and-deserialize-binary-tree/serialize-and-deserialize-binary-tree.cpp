/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root==NULL) 
            return "";
        
        TreeNode* curr;
        string levelOrderTraversal="";
        //Queue is used as we want to traverse the nodes level by level from left to right
        //So queue can maintain the order
        queue<TreeNode*> q; 
        q.push(root);
        while(!q.empty())
        {
            int nodesAtCurrLevel=q.size();
            while(nodesAtCurrLevel--)
            {
                curr=q.front();
                q.pop();
                if(curr)
                {
                    levelOrderTraversal+=to_string(curr->val);
                }
                else
                {
                   levelOrderTraversal+='N';
                }
                 levelOrderTraversal+=',' ;
                if(curr)
                    q.push(curr->left);
               
                
                if(curr)
                    q.push(curr->right);

            }  
        }
        cout<<levelOrderTraversal;
        return levelOrderTraversal;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.size()==0)
            return NULL;
        
        queue <TreeNode*> q1;
        
        vector<int> nodeValues;
        
        stringstream dataStream(data);
        string substr;
        while(getline(dataStream,substr,','))
        {
            if(substr=="N")
                nodeValues.push_back(INT_MIN);
            else
                nodeValues.push_back(stoi(substr));
        }
    
        int i=0;
        TreeNode* root=new TreeNode(nodeValues[i++]);
        q1.push(root);
        
        while(i<nodeValues.size())
        {
            TreeNode* newNode=q1.front();
            q1.pop();
            
            if(nodeValues[i]!=INT_MIN)
            {
                newNode->left=new TreeNode(nodeValues[i]);
                q1.push(newNode->left);
            }
            i++;
            if(nodeValues[i]!=INT_MIN)
            {
                newNode->right=new TreeNode(nodeValues[i]);
                q1.push(newNode->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));