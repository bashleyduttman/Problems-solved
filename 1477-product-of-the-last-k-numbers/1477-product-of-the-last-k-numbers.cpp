class ProductOfNumbers {
public:
    vector<int> product;
    int n;
    ProductOfNumbers() {
        n = 0;


        product.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            n = 0;

            product.clear();
            product.push_back(1);
        } else {
            
            product.push_back(product[n] * num);
                
            
            n++;
        }
    }

    int getProduct(int k) { 
        if(k>n) return 0;
        return product[n] / product[n - k]; }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */