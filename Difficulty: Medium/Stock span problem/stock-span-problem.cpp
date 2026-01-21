class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st; // stack to store indices

        for (int i = 0; i < n; i++) {
            // Pop elements while current price is greater or equal
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack empty, span is i+1
            if (st.empty()) {
                span[i] = i + 1;
            } else {
                span[i] = i - st.top();
            }

            // Push current index
            st.push(i);
        }

        return span;
    }
};

