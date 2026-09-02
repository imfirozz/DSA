class Solution {
public:
    int solve(int n, string s) {
        vector<bool> seen(26, false);
        vector<bool> usingComputer(26, false);

        int occupied = 0;
        int rejected = 0;

        for (char c : s) {
            int id = c - 'A';

            if (!seen[id]) {
                // Arrival
                seen[id] = true;

                if (occupied < n) {
                    occupied++;
                    usingComputer[id] = true;
                } else {
                    rejected++;
                }
            } 
            else {
                // Departure
                if (usingComputer[id]) {
                    occupied--;
                    usingComputer[id] = false;
                }
            }
        }

        return rejected;
    }
};