# Remove Duplicates from Sorted Array

## Problem
[Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array)

## Approach
- Initialize a variable to keep track of the index.
- Iterate over the array.
- If the number is not equal to the previous number, increment the index.
- Set the value of the index to the current number.
- Return the index.


```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int temp = 1;
        for (int i = 1; i < n; i++ ){
            if (nums[i] != nums[i-1]){
                nums[temp] = nums[i];
                temp++;
            }
        }
        return temp;
    }
};
```