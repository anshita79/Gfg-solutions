class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq; // To store indices
        
        for (int i = 0; i < arr.size(); i++) {
            // 1. Remove indices that are out of the current window range
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // 2. Remove indices of elements smaller than the current element
            // because they will never be the maximum in this or future windows
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            
            // 3. Add the current element's index
            dq.push_back(i);
            
            // 4. Once we have reached at least 'k' elements, the front is our max
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }
        
        return result;
    }
};