class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s(dictionary.begin(), dictionary.end());
        string temp = "", res = "";
        bool consider = true;
        for(auto ch : sentence) {
            if(ch == ' ') {
                if(temp.size() > 0) res += temp + " ";
                temp = "", consider = true;
                continue;
            }
            if(!consider) continue;
            temp += ch;
            if(s.count(temp)) {
                consider = false;
                res += temp + " ";
                temp = "";
            }
        }
        res += temp;
        if(res.back() == ' ') res.pop_back();
        return res;
    }
};