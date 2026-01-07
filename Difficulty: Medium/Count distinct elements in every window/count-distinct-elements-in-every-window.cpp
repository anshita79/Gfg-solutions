class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result;
        unordered_map<int, int> freqMap;
        int n = arr.size();

        // 1. Process the first window
        for (int i = 0; i < k; i++) {
            freqMap[arr[i]]++;
        }
        result.push_back(freqMap.size());

        // 2. Slide the window
        for (int i = k; i < n; i++) {
            // Remove the element going out of the window
            int out_elem = arr[i - k];
            freqMap[out_elem]--;
            
            if (freqMap[out_elem] == 0) {
                freqMap.erase(out_elem);
            }

            // Add the new element coming into the window
            int in_elem = arr[i];
            freqMap[in_elem]++;

            // The current size of map represents distinct elements
            result.push_back(freqMap.size());
        }

        return result;
    }
};