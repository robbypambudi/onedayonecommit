# Remove Element

## Problem
[Leetcode](https://leetcode.com/problems/remove-element/)

## Approach
1. Iterate over the vector and remove the element if it is equal to the given value.
2. Return the size of the vector.

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()){
            return {};
        }
        int index = 0;
        for (auto it = nums.begin(); it != nums.end(); it++){
            if (nums[index] == val){
                nums.erase(it);
                it-=1;
            }else {
                index++;
            }
        }

        return nums.size();
        
    }
};
```