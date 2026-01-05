class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return 0;

        long long current_sum = 0;
        // 1. Calculate sum of the first window
        for (int i = 0; i < k; i++) {
            current_sum += arr[i];
        }

        long long max_sum = current_sum;

        // 2. Slide the window from index k to the end of the array
        for (int i = k; i < n; i++) {
            // Add the next element and remove the first element of the previous window
            current_sum += arr[i] - arr[i - k];
            // 3. Keep track of the highest sum seen so far
            max_sum = max(max_sum, current_sum);
        }

        return (int)max_sum;
    }
};