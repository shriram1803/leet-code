class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        map<int, int> freq;
        vector<pair<int, int>> freq_arr;
        unordered_set<int> s;
        
        for(int num : nums)
            ++freq[num];
        
        for(auto it : freq)
            freq_arr.emplace_back(it);
        
        for(int i = 0; i < freq_arr.size(); ++i) {
            int value = freq_arr[i].first;
            if(freq_arr[i].second > 2)
                s.insert(value);
            if(freq_arr[i].second > 1 and s.count(value * -2))
                res.push_back({value * -2, value, value});
            if(freq_arr[i].second > 1)
                s.insert(value);
            for(int j = i + 1; j < freq_arr.size(); ++j) {
                if(s.count(-(value + freq_arr[j].first)))
                    res.push_back({-(value + freq_arr[j].first), value, freq_arr[j].first});
            }
            s.insert(value);
        }
        
        return res;
    }
};