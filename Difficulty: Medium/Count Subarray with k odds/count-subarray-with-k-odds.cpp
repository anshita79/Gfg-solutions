class Solution {
public:
    // Helper function to count subarrays with AT MOST 'k' odd numbers
    int countAtMost(vector<int>& arr, int k) {
        if (k < 0) return 0;
        
        int start = 0, count = 0, oddCount = 0;
        
        for (int end = 0; end < arr.size(); end++) {
            // If the current number is odd, increase our odd counter
            if (arr[end] % 2 != 0) {
                oddCount++;
            }
            
            // If we have more than k odds, shrink the window from the left
            while (oddCount > k) {
                if (arr[start] % 2 != 0) {
                    oddCount--;
                }
                start++;
            }
            
            // The number of subarrays ending at 'end' is (end - start + 1)
            count += (end - start + 1);
        }
        return count;
    }

    int countSubarrays(vector<int>& arr, int k) {
        // Exactly K = (At most K) - (At most K-1)
        return countAtMost(arr, k) - countAtMost(arr, k - 1);
    }
};