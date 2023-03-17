/*
Code Link -https://leetcode.com/problems/implement-trie-prefix-tree/

TC - 
void insert(String word) - O(len(word))
boolean search(String word) - O(len(word))
boolean startsWith(String prefix) - O(len(word))

Link - https://www.youtube.com/watch?v=K5pcpkEMCN0&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=2

SC - 

*/

class Node
{
    Node* links[26];
    bool flag = false;
    public:
        bool containsKey(char c)
        {
            return links[c-'a']!=NULL;
        }

        void putKey(char c,Node* node)
        {
            links[c-'a'] = node;
        }

        Node* getKey(char c)
        {
            return links[c-'a'];
        }

        void setEnd()
        {
            flag = true;
        }

        bool isEnd()
        {
            return flag;
        }
};
class Trie 
{
    Node* root = NULL;
public:
    Trie() 
    {
        root = new Node();
    }
    
    void insert(string word) 
    {
        Node* node = root;
        
        for(int i = 0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->putKey(word[i],new Node());
            }
            
            node = node->getKey(word[i]);
        }
        
        node->setEnd();
    }
    
    bool search(string word) 
    {
        Node* node = root;
        
        for(int i = 0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->getKey(word[i]);
        }
        
        return node->isEnd();
    }
    
    bool startsWith(string prefix) 
    {
        Node* node = root;
        
        for(int i = 0;i<prefix.size();i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->getKey(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */