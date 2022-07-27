/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        Node* root = head;
        
        while(root)
        {
            if(root->child)
            {
                Node* temp = root->child;
                while(temp->next)
                {
                    temp = temp->next;
                }
                if(root->next)
                {
                    temp->next = root->next;
                    root->next->prev = temp;
                }
                root->next = root->child;
                root->child->prev = root;
                root->child = NULL;
            }
            root = root->next;
        }
        return head;
    }
};