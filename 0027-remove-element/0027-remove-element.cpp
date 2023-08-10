class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int front = 0, back = nums.size() - 1;
        
        while(front <= back) {
            while(back >= 0 and nums[back] == val) back -= 1;
            while(front < back and nums[front] != val) front += 1;
            
            if(front == back)
                break;
            
            if(front < back)
                swap(nums[front], nums[back]);
        }
        
        return back + 1;
    }
};