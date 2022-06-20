class LRUCache 
{
    list<pair<int,int>> queue;
    unordered_map<int,list<pair<int,int>>::iterator> keyIndex;
    int maxcap;

public:
    LRUCache(int capacity) 
    {
        keyIndex.clear();
        queue.clear();
        maxcap= capacity;
    }
    
    int get(int key) 
    {
        if(keyIndex.find(key)!=keyIndex.end())
        {
            int value = keyIndex[key]->second;
            queue.erase(keyIndex[key]);
            queue.push_back({key,value});
            keyIndex[key] = --queue.end();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(keyIndex.find(key)!=keyIndex.end())
        {
            queue.erase(keyIndex[key]);
        }
        else
        {
            if(keyIndex.size()==maxcap)
            {
                int frontKey = queue.front().first;
                keyIndex.erase(frontKey);
                queue.pop_front();
            }
        }
        queue.push_back({key,value});
        keyIndex[key] = --queue.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */