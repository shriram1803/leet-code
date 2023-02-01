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
        string merge = str1 + str2, curr = "", curr1 = "";
        int n1 = str1.size(), n2 = str2.size();
        for(int i = 0; i < min(str1.size(), str2.size()); ++i) {
            curr += str1[i], curr1 += str2[i];
            if(n1 % (i + 1) != 0 or n2 % (i + 1) != 0) continue;
            if(curr != curr1) return res;
            if(repeat(curr, n1 / (i + 1)) == str1 and repeat(curr, n2 / (i + 1)) == str2){
                res = curr;
            }
        }  
        return res;
    }
};