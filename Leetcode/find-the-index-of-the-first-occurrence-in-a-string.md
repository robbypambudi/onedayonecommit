# Find the Index of the First Occurrence in a String

## Problem Statement

[Leetcode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

## Approach

1. Use the `find` method of the string class to find the first occurrence of the needle in the haystack.
2. If the needle is found, return the index.
3. If the needle is not found, return -1.

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int found = haystack.find(needle);
        if (found != -1){
            return found;
        }

        return -1;
    }
};
```

## Complexity Analysis
O(N+M) where N is the length of the haystack and M is the length of the needle.

## Better Approach

```cpp
class Solution {
 public:
  int strStr(string haystack, string needle) {
    const int m = haystack.length();
    const int n = needle.length();

    for (int i = 0; i < m - n + 1; i++)
      if (haystack.substr(i, n) == needle)
        return i;

    return -1;
  }
};
```