class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        string m = "";
        for (int i = 0; i < details.size(); i++) {
            m += details[i];
        }
        int ans = 0;
        for (int i = 0; i < m.size(); i++) {

            if (m[i] == 'M' || m[i] == 'F' || m[i]=='O') {
                ans = (m[i + 1] - '0') * 10 + (m[i + 2] - '0');

                if (ans > 60) {
                    count++;
                }
            }
        }
        return count;
    }
};