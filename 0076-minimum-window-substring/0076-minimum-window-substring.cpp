class Solution {
public:
    int charToInt(char& ch) {
        if('a' <= ch and ch <= 'z') {
            return ch - 'a';
        }
        return (ch - 'A') + 26;
    }
    string minWindow(string s, string t) {
        
        int m = s.size();
        int mini = 1e9;
        int res_start = 0;
        vector<int> freqs(52), freqt(52);
        
        int uniq = 0;
        for(auto& ch : t) {
            if(freqt[charToInt(ch)] == 0)
                uniq += 1;
            freqt[charToInt(ch)] += 1;
        }
        
        int matched = 0;
        int vali, valj;
        for(int i = 0, j = 0; i < m; ++i) {
            
            vali = charToInt(s[i]);  
            freqs[vali] += 1;
            if(freqs[vali] == freqt[vali])
                matched += 1;  
            
            while(j <= i and matched == uniq) {
                valj = charToInt(s[j]);
                if(i - j + 1 < mini) {
                    mini = i - j + 1;
                    res_start = j;
                }
                freqs[valj] -= 1;
                if(freqs[valj] < freqt[valj])
                    matched -= 1;
                j += 1;
            }                                      
        }
        
        if(mini == 1e9)
            return "";
        
        return s.substr(res_start, mini);
    }
};