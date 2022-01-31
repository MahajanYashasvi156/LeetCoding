class LRUCache {
public:
    /*Two datastructures- All Operations in O(1).
    Doubly Linked List - Stores Key, value in each node.(Cache Implementation)
    unordered map - Key ,address of the node of the Doubly linked list.(order of keys not matters so can use unordered map instead of map)
    */
    list <pair<int,int>> lqueue;
    unordered_map<int,list <pair<int,int>> ::iterator >lmap;
    int cap;
    
    LRUCache(int capacity) 
    {
        cap=capacity;
    }
    //To access the value of the key (Time - O(1)).
    int get(int key) 
    {
        //If key not exist then we have to writtern -1 value.
        int value=-1;
        //If key exist in the map then we have to reset the key,value pair node to the last of the queue.
        if(lmap.find(key)!=lmap.end())
        {
            list <pair<int,int>> ::iterator it;
            //Find the address of the node of the key,value pair in the queue(DLL).
            it=lmap[key];
            //value of the access key.
            value=it->second;
            //Delete this node from the current position.
            lqueue.erase(it);
            //Add it to the end of the List(queue).
            lqueue.push_back({key,value});
            //Update the address of the node in the map corresponding to the key.
            lmap[key]=--lqueue.end();
        }
        return value;
    }
    
    //To insert the key, value in the cache - Time O(1).
    void put(int key, int value)
    {
        //If the Key not present already in the Cache.
        if(lmap.find(key)==lmap.end())
        {
            //If the Cache is full.We have to evict the LRU key from the cache.
            if(cap==lqueue.size())
            {
                //LRU key is the key in the first node of the List/Queue.
                //Delete this key from the queue and map.
                lmap.erase(lqueue.begin()->first); 
                lqueue.pop_front(); 
            } 
            //Add the new key,value in the queue at the end.
            lqueue.push_back({key,value});
            //Add the new key with its address to the map.
            lmap[key]=--lqueue.end();
        }
        //If the Key already present.
        else
       {
            //Delete the key,value pair from the queue.
            lqueue.erase(lmap[key]);
            //Add it to the end of the queue.
            lqueue.push_back({key,value});
            //Update the address of the key.
            lmap[key]=--lqueue.end();  
       }
       
    }
};
