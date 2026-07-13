class ProductOfNumbers {
public:
vector<int> pro;
int s;
    ProductOfNumbers() {
        pro={1};
        s=1;
    }
    
    void add(int num) {
        if(num==0)
        {
            pro={1};
            s=1;
        }
        else
        {
            pro.push_back(pro[s++-1]*num);

        }
        
    }
    
    int getProduct(int k) {
        if(s<=k) return 0;
        return pro[s-1]/pro[s-k-1];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */