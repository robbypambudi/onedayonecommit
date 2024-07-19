
# Search Insert Position

[Leetcode](https://leetcode.com/problems/search-insert-position/)

## Approach
1. Use binary search to find the index of the target.
2. If the target is found, return the index.
3. If the target is not found, return the index where the target should be inserted.

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};
```