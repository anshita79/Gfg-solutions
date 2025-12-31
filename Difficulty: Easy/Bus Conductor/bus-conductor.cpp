class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // Step 1: Sort both arrays to align the positions
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        
        int totalMoves = 0;
        int n = chairs.size();
        
        // Step 2: Sum the absolute differences
        for (int i = 0; i < n; i++) {
            totalMoves += abs(chairs[i] - passengers[i]);
        }
        
        return totalMoves;
    }
};