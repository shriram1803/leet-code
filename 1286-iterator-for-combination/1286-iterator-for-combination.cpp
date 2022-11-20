class CombinationIterator {
public:
    vector<string> bank;
    int itr = 0;
    void solve(vector<string>& res, string s, int ind, int cnt, string curr, const int n) 
    {
        if(cnt > n) return;
        if(ind == s.size()) {
            if(cnt == n) res.push_back(curr);
            return;
        }
        solve(res, s, ind + 1, cnt + 1, curr + s[ind], n);
        solve(res, s, ind + 1, cnt, curr, n);
    }
    CombinationIterator(string characters, int combinationLength) {
        solve(bank, characters, 0, 0, "", combinationLength);
    }
    
    string next() {
        return bank[itr++];
    }
    
    bool hasNext() {
        if(itr < bank.size()) return 1;
        return 0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */