class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // long long x = num / 3 - 1;
        // if(3*x + 3 == num) return {x, x + 1, x + 2}; 
        // long long x = num / 3;
        // while(x > num / 4) {
        //     if(3*x + 2 == num) {
        //         return {x, x + 1, x + 2};
        //     }
        //     x--;
        // }
        
        if(num % 3 == 0) {
            return {num / 3 - 1, num / 3, num / 3 + 1};
        }
        
        return {};
    }
};