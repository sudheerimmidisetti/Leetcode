class ProductOfNumbers {

public:
    vector<int> prefPro;
    ProductOfNumbers() {
        prefPro.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefPro.clear();
            prefPro.push_back(1);
        } else
            prefPro.push_back(prefPro.back() * num);
    }

    int getProduct(int k) {
        int n = prefPro.size();
        if (k >= n)
            return 0;

        return prefPro[n - 1] / prefPro[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */