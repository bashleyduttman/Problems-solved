class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0; // Base case: First row is always 0
        
        int mid = (1 << (n - 2)); // Half of row length
        
        if (k <= mid) 
            return kthGrammar(n - 1, k); // First half (same as previous row)
        else 
            return !kthGrammar(n - 1, k - mid); // Second half (complement)
    }
};
