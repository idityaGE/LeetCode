import java.util.*;

class ProductOfNumbers {
    private List<Integer> prefixProduct;
    
    public ProductOfNumbers() {
        prefixProduct = new ArrayList<>();
    }

    public void add(int num) {
        if (num == 0) {
            prefixProduct.clear(); // Reset when zero is added
        } else {
            if (prefixProduct.isEmpty()) {
                prefixProduct.add(num);
            } else {
                prefixProduct.add(prefixProduct.get(prefixProduct.size() - 1) * num);
            }
        }
    }

    public int getProduct(int k) {
        int size = prefixProduct.size();
        if (size < k) return 0; // If not enough elements, return 0
        if (size == k) return prefixProduct.get(size - 1);
        return prefixProduct.get(size - 1) / prefixProduct.get(size - k - 1);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */
