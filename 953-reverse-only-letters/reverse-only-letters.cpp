class Solution {
public:
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z');
    }

    string reverseOnlyLetters(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
// chrek if letter is btw a to z or A to Z if not move to next
            if (!isLetter(s[start])) {
                start++;
            }
            // same here check last letter is btw a to z or A to Z if not then move 
            else if (!isLetter(s[end])) {
                end--;
            }

            // both true then swap the char
            else {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }

        return s;
    }
};