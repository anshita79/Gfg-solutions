class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                // If the element is 0, swap it with the element at 'low'
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } 
            else if (arr[mid] == 1) {
                // If the element is 1, it's already in the right place (the middle)
                mid++;
            } 
            else { // arr[mid] == 2
                // If the element is 2, swap it with the element at 'high'
                swap(arr[mid], arr[high]);
                high--;
                // Note: We don't increment mid here because the new element 
                // swapped from 'high' hasn't been processed yet.
            }
        }
    }
};