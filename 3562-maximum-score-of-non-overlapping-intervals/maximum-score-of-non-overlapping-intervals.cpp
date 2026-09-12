class Solution {
public:

    struct Node {
        int l, r, weight, index;
    };

    struct Result {
        long long score;
        vector<int> indices;
    };

    vector<Node> a;
    vector<vector<Result>> dp;
    int n;

    Result solve(int i, int k) {

        if(i == n || k == 0)
            return {0, {}};

        if(dp[i][k].score != -1)
            return dp[i][k];

        // Don't take current interval
        Result skip = solve(i + 1, k);

        // Take current interval
        int r = a[i].r;

        int left = i + 1;
        int right = n;

        // Find first interval with l > r
        while(left < right) {
            int mid = left + (right - left) / 2;

            if(a[mid].l > r)
                right = mid;
            else
                left = mid + 1;
        }

        int next = left;

        Result take = solve(next, k - 1);

        take.score += a[i].weight;
        take.indices.push_back(a[i].index);

        sort(take.indices.begin(), take.indices.end());

        // Compare skip and take
        if(take.score > skip.score) {
            return dp[i][k] = take;
        }

        if(take.score < skip.score) {
            return dp[i][k] = skip;
        }

        // Same score
        if(take.indices < skip.indices)
            return dp[i][k] = take;

        return dp[i][k] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        a.clear();

        for(int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end(), [](Node &x, Node &y) {
            return x.l < y.l;
        });

        dp.assign(n, vector<Result>(5));

        for(int i = 0; i < n; i++) {
            for(int k = 0; k < 5; k++) {
                dp[i][k].score = -1;
            }
        }

        return solve(0, 4).indices;
    }
};