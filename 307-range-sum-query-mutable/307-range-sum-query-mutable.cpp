class SegmentTree
{   
    vector<int>st;
    public: 
        SegmentTree(int n) 
        {
            int totalNodes = 2*n - 1 ;
            int height = ceil(log2(totalNodes));
            int size = pow(2,height);
            st.resize(size);
        }
        void BuildTree(int i,vector<int>&nums,int l, int r)
        {
            if(l==r)
            {
                st[i] = nums[l];
                return;
            }
            int mid = (l+r)/2;
            BuildTree(2*i+1,nums,l,mid);
            BuildTree(2*i+2,nums,mid+1,r);
            st[i] = st[2*i+1]+st[2*i+2];
        }
    
        int calculateSum(int i,int sl,int sr,int l,int r)
        {
            if(sr<l || sl>r)
                return 0;
            if(sl>=l and sr<=r)
                return st[i];
            int mid = (sl+sr)/2;
            return calculateSum(2*i+1,sl,mid,l,r) + calculateSum(2*i+2,mid+1,sr,l,r);
        }
    
        void updateVal(int i,int index,int change,int sl,int sr)
        {
            if(sr<index || sl>index)
                return ;
            st[i] = st[i]+change;
            if(sl!=sr)
            {
                int mid = (sl+sr)/2;
                updateVal(2*i+1,index,change,sl,mid);
                updateVal(2*i+2,index,change,mid+1,sr);
            }
        }
};
class NumArray 
{
    SegmentTree* st;
    vector<int> nums;
public:
    NumArray(vector<int>& arr) 
    {
        nums.insert(nums.end(),arr.begin(),arr.end());
        st = new SegmentTree(nums.size());
        st->BuildTree(0,nums, 0, nums.size()-1);
    }
    
    void update(int index, int val) 
    {
        int change = val-nums[index];
        st->updateVal(0,index,change,0,nums.size()-1);
        nums[index] = val; //update original array as well.
    }
    
    int sumRange(int left, int right) 
    {
        return st->calculateSum(0,0,nums.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */