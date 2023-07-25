/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak_ind(MountainArray& arr) {
        int left = 1, right = arr.length() - 2, mid, curr, next;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            
            curr = arr.get(mid);
            next = arr.get(mid + 1);
            if(next < curr)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return left;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = peak_ind(mountainArr);
        
        int res = -1;
        
        // Reverse binary search
        int left = peak, right = mountainArr.length() - 1, mid, curr;
        while(left <= right) {
            mid = left + (right - left) / 2;
            curr = mountainArr.get(mid);
            if(curr > target) {
                left = mid + 1;
            } else if(curr < target) {
                right = mid - 1;
            } else {
                res = mid;
                break;
            }
        }
        
        // Regular binary search
        left = 0, right = peak, mid, curr;
        while(left <= right) {
            mid = left + (right - left) / 2;
            curr = mountainArr.get(mid);
            if(curr < target) {
                left = mid + 1;
            } else if(curr > target) {
                right = mid - 1;
            } else {
                res = mid;
                break;
            }
        }
        
        return res;
    }
};