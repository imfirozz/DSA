class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int totalTime = 0;

        for(int i = 0; i <= k; i++) {

            if(tickets[i] >= tickets[k])
                totalTime += tickets[k];
            else
                totalTime += tickets[i];
        }

        for(int i = k + 1; i < tickets.size(); i++) {

            if(tickets[i] >= tickets[k])
                totalTime += tickets[k] - 1;
            else
                totalTime += tickets[i];
        }

        return totalTime;
    }
};