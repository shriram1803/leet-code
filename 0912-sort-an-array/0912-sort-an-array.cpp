int temp[50001] = { 0 };

class Solution {
public:
    void merge(vector<int>& nums, int start, int end) {
        
        int i, j, ind, mid = (start + end) / 2;
        
        for(i = start, j = mid + 1, ind = 0; i <= mid or j <= end;) {
            if(i <= mid and j <= end) {
                if(nums[i] < nums[j]) {
                    temp[ind] = nums[i], ++i;
                } else {
                    temp[ind] = nums[j], ++j;
                }
            } else if(i <= mid) {
                temp[ind] = nums[i], ++i;
            } else {
                temp[ind] = nums[j], ++j;
            }
            ++ind;
        }
        
        for(int i = 0, j = start; i < ind; ++i, ++j) {
            nums[j] = temp[i];
        }
        
    }
    
    void mergeSort(vector<int>& nums, int start, int end) {
        
        if(start >= end)
            return;
        
        int mid = (start + end) / 2;
        
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        
        merge(nums, start, end);
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};