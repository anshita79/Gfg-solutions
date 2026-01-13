class Solution {
public:
    bool canServe(vector<int> &arr) {
        int five = 0;
        int ten = 0;

        for (int note : arr) {
            if (note == 5) {
                five++;
            } 
            else if (note == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false; // Cannot give 5 change
                }
            } 
            else { // note is 20
                // Try to give change using one 10 and one 5 (Greedy)
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } 
                // Otherwise, try to give three 5s
                else if (five >= 3) {
                    five -= 3;
                } 
                else {
                    return false; // Cannot give 15 change
                }
            }
        }
        return true;
    }
};