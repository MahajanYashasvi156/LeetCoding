class ProductOfNumbers 
{
    vector<int> prefixProduct;
    long long prod = 1;
    
public:
    ProductOfNumbers() 
    {
        
    }
    
    void add(int num) 
    {
        if(num==0)
        {
            prefixProduct.clear();
            prod = 1;
        }
        else
        {
            prod = prod*num;
            prefixProduct.push_back(prod);
        }
    }
    
    int getProduct(int k)
    {
        if(prefixProduct.size()<k)
            return 0;
        int ans = prefixProduct[prefixProduct.size()-1];
        
        if(prefixProduct.size()==k)
            return ans;
       return ans/prefixProduct[prefixProduct.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */