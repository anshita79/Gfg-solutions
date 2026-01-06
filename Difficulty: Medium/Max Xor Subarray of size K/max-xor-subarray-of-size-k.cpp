class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return 0; // Boundary check

        int currentXor = 0;
        // Step 1: Compute XOR for the first window of size k
        for (int i = 0; i < k; i++) {
            currentXor ^= arr[i];
        }

        int maxXor = currentXor;

        // Step 2: Use sliding window to find max XOR for other subarrays
        for (int i = k; i < n; i++) {
            // Remove element at (i - k) and add element at i
            currentXor = currentXor ^ arr[i - k] ^ arr[i];
            
            // Update the maximum XOR found so far
            if (currentXor > maxXor) {
                maxXor = currentXor;
            }
        }

        return maxXor;
    }
};