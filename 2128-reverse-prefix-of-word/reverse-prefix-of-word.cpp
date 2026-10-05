class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;
        int i = 0;

        while (i<=word.size()) {
            if (word[i] == ch) {
                index = i;
                break;
            }
            i++;
        }
    
        int st = 0, end = index;

        while (st < end) {
            swap(word[st], word[end]);
            st++;
            end--;
        }

        return word;
    }
};