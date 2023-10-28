class Solution {
public:
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string reverseVowels(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while(left < right) {
            while(left < right and !vowels.count(s[left])) ++left;
            while(right > left and !vowels.count(s[right])) --right;
            swap(s[left], s[right]);
            ++left;
            --right;
        }
        return s;
    }
};