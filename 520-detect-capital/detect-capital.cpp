class Solution {
public:
    bool detectCapitalUse(string word) {
        int count_Capital = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z')
                count_Capital++;
        }
        if (count_Capital == word.size())
            return 1;
        if (!count_Capital)
            return 1;
        if (count_Capital == 1) {
            if (word[0] >= 'A' && word[0] <= 'Z')
                return 1;
        }

        return 0;
    }
};