# Three Consecutive Odds

## Problem
[Link](https://leetcode.com/problems/three-consecutive-odds/)

## Approach
- Initialize a flag to keep track of the number of consecutive odd numbers.
- Iterate over the array.
- If the number is odd, increment the flag.
- If the flag is equal to 3, return true.
- If the number is even, reset the flag.
- Return false.

## Code (Not Optimized)
```cpp
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int flag = 0;
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] % 2 == 1){
                flag +=1;    
                if (flag == 3){
                    return true;
                }
            } 
            else {
                flag = 0;
            }
        }
    return false;
    }
};
```

## Code (Optimized)
```cpp
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int flag = 0;
        int n = arr.size();
        if (n < 2){
            return false;
        }
        for (int i = 0; i < n - 2; i++){
            int product = arr[i] * arr[i + 1] * arr[i + 2];
            if (product % 2 == 1) return true;
        }
    return false;
    }
};
```

## Code (Best)
```cpp
// Using a sliding window approach to solve the problem.
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        int left = 0, right = 0;
        while (right < n) {
            if (arr[right] % 2 == 1) {
                if (right - left + 1 == 3) return true;
            } else {
                left = right + 1;
            }
            right++;
        }
        return false;
    }
};
```
