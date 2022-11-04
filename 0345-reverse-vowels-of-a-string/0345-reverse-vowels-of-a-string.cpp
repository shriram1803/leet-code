class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> x{'a','i','e','o','u','A','E','I','O','U'};
        int start = 0, end = s.size() - 1;
        while(start < end){
            while(start < end and !x.count(s[start])) start++;
            while(end > start and !x.count(s[end])) end--;
            swap(s[start++], s[end--]);
        }
        return s;
    }
};