class MyHashMap {
public:
    int mymap[1000001];
    MyHashMap()
    {
      memset(mymap,-1,sizeof(mymap)); 
    } 
    void put(int key, int value) 
    {
        mymap[key]=value;
    }
    int get(int key) 
    {
        return mymap[key];  
    }
    void remove(int key) 
    {
        mymap[key]=-1;
    }
};

//Have to do with chaining.
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */