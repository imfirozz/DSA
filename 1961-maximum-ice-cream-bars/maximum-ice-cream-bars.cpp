class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        long long  total = 0;
        for (int i = 0; i < costs.size(); i++) {
            total += costs[i];
             if (total <= coins) { count++; }
        }
        return count;
    }
};