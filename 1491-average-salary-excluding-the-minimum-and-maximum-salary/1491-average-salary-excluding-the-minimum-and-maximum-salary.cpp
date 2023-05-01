class Solution {
public:
    double average(vector<int>& salary) {
        int total = 0, minn = INT_MAX, maxx = INT_MIN, n = salary.size();
        for(int s : salary) {
            total += s;
            minn = min(minn, s);
            maxx = max(maxx, s);
        }
        return (total - minn - maxx) / (double)(n - 2);
    }
};