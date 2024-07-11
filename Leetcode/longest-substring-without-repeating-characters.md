# Longest Substring Without Repeating Characters

## Problem
[Problem](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Approach
> Using a sliding window approach to solve the problem.
1. Initialize a set to store the unique characters.
2. Initialize the maximum length of the substring.
3. Initialize the left and right pointers.
4. Iterate over the string until the right pointer reaches the end of the string.
5. If the character is not in the set, add the character to the set and update the maximum length.
6. If the character is in the set, remove the character from the set and move the left pointer.
7. Return the maximum length.


## Code 
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char> unique;
        int maxLength = 0, left = 0, right = 0;

        while (right < n) {
            if (unique.find(s[right]) == unique.end()) {
                unique.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                unique.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};
```