class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int target = arr.size() / 4;
        int count = 0;
        int prev = -1;
        
        for(int num : arr) {
            if(num == prev)
                count += 1;
            else
                count = 1;
            if(count > target)
                return num;
            prev = num;
        }
        
        return -1;
    }
};