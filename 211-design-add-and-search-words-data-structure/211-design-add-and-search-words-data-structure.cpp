struct Node
{
    Node *links[26];
    bool flag = false;
    
    bool containsKey(char c)
    {
        if(links[c-'a']==NULL)
            return false;
        return true;
    }
    
    void put(char c, Node* node)
    {
        links[c-'a']=node;
    }
    
    Node* get(char c)
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


class WordDictionary 
{
    Node *root;
public:
    WordDictionary() 
    {
        root = new Node();
    }
    bool searchWord(Node* node,string word,int i) 
    {
        if(i==word.size())
            return node->isEnd();
        
        if(word[i]!='.')
        {
            if(node->containsKey(word[i])==false)
            {
                return false;
            }
            node = node->get(word[i]);
            return searchWord(node,word,i+1);
        }
        else
        {
            for(char ch = 'a';ch<='z';ch++)
            {
                if(node->containsKey(ch))
                {
                    if(searchWord(node->get(ch),word,i+1))
                        return true;
                }
                
            }
            return false;
        }
        return false; 
    }
    
    void addWord(string word) 
    {
        Node *node = root;
        for(char c : word)
        {
            if(node->containsKey(c)==false)
            {
                node->put(c,new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }
    
    bool search(string word) 
    {
        return searchWord(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */