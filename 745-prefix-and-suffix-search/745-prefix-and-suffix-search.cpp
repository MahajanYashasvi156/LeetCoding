/*
We need to find a string which has both pref and suff in it. 

So we need to store strings in a trie such that both prefixes and suffices can be checked optimally. 

We store string "apple" as - 

apple{apple
pple{apple
ple{apple
le{apple
e{apple

"{" asciee value of this character is just after z. Before { , suffix and after { prefix is checked.

we can store all suffixes and prefixes separately but to identify whether both suffic and prefix matched with same string would be cumbersome. So completerstring(for prefix) followed by suffix is maintained.

*/
class Node
{
    public:
    Node* links[27];
    int index = -1;
};
class Trie
{
    public :
    Node* root;
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(string s,int index)
    {
        Node* curr = root;
        
        for(int i = 0;i<s.size();i++)
        {
            if(curr->links[s[i]-'a']==NULL)
                curr->links[s[i]-'a'] = new Node();
            curr = curr->links[s[i]-'a'];
            curr->index = max(index,curr->index);
        }
    }
    
    int search(string s)
    {
        Node* curr = root;
        
        for(int i = 0;i<s.size();i++)
        {
            if(curr->links[s[i]-'a']==NULL)
                return -1;
            curr = curr->links[s[i]-'a'];
            
        }
        return curr->index;
    }
};
class WordFilter 
{
public:
    Trie trie;
    WordFilter(vector<string>& words) 
    {
        for(int i = 0;i<words.size();i++)
        {
            string s = "";
            for(int j = words[i].size()-1;j>=0;j--)
            {
                s = words[i][j]+s;
                trie.insert(s+"{"+words[i],i);
            }
        }
    }
    
    int f(string pref, string suff) 
    {
        string temp = suff+"{"+pref;
        return trie.search(temp);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */