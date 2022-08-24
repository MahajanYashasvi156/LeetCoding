class SnapshotArray 
{
    map<int,map<int,int>> snapInfo; //index , snap_id , value
    int id = 0;
    
public:
    SnapshotArray(int length)
    {
        for(int i = 0;i<length;i++)
            snapInfo[i][id] = 0;
    }
    
    void set(int index, int val) 
    {
        snapInfo[index][id] = val;   
    }
    
    int snap() 
    {
        return id++;
    }
    
    int get(int index, int snap_id) 
    {
        auto it = snapInfo[index].upper_bound(snap_id) ;
 
        return (--it)->second; 
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */