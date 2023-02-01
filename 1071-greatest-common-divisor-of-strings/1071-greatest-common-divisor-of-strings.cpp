class Solution {
public:
    string repeat(string s, int n) {
        string s1 = s;
        for (int i=1; i<n;i++)
            s += s1;
        return s;
    }
    string gcdOfStrings(string str1, string str2) {
        string res = "";
        string merge = str1 + str2, curr = "";
        int n1 = str1.size(), n2 = str2.size();
        for(int i = 0; i < min(str1.size(), str2.size()); ++i) {
            curr += merge[i];
            if(n1 % (i + 1) != 0 or n2 % (i + 1) != 0) continue;
            if(repeat(curr, (n1 + n2) / (i + 1)) == merge) {
                res = curr;
            }   
        }        
        return res;
    }
};