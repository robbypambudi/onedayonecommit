# Palindrome Number

## Problem
[Link](https://leetcode.com/problems/palindrome-number)

## Solution
1. Convert number to string.
2. Loop through the string from both ends.
3. If the characters at both ends are not equal, return false.
4. If the loop completes, return true.

```cpp
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        string nstr = to_string(x);

        int i = 0, j = nstr.length() - 1;

        while (i <= j)
        {
            if (nstr[i] != nstr[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
```