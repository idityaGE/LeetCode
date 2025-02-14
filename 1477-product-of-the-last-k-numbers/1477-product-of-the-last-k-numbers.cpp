class ProductOfNumbers {
public:
    vector<int> product;
    int prod = 1;

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            product.clear();
            prod = 1;
        } else {
            prod *= num;
            product.push_back(prod);
        }
    }

    int getProduct(int k) {
        if (product.size() < k)
            return 0;
        if (product.size() == k)
            return product.back();
        return product.back() / product[product.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */