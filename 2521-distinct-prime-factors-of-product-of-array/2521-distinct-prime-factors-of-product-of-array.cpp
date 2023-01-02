class Solution {
public:
    void solve(int num, unordered_set<int>& s) {
        if(num % 2 == 0) {
            s.insert(2);
            while(num % 2 == 0) {
                num /= 2;
            }
        }
        for(int i = 3; i <= sqrt(num); i += 2) {
            while(num % i == 0) {
                s.insert(i);
                num /= i;
            }
        }
        if(num > 2) 
            s.insert(num);
        return;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums) {
            solve(num, s);
        }
        return s.size();
    }
};