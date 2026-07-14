class Solution {
public:
    bool IsShipWithing(int capacity, vector<int>& weights, int days)
    {
        int usedDays = 1;
        int currentLoad = 0;

        for (int weight : weights)
        {
            if (currentLoad + weight <= capacity)
            {
                currentLoad += weight;
            }
            else
            {
                usedDays++;
                currentLoad = weight;
            }
        }

        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days)
    {
        int start = 0, end = 0;
        int ans = 0;

        for (int weight : weights)
        {
            start = max(start, weight);
            end += weight;
        }

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (IsShipWithing(mid, weights, days))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};