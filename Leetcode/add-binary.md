# Add Binary

## Problem
[Add Binary](https://leetcode.com/problems/add-binary/)

## Approach
> Using Bit Manipulation

1. Initialize two pointers `N` and `M` to the length of the strings `a` and `b` respectively.
2. Initialize a variable `carry` to `0`.
3. Initialize an empty string `ans`.

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
     int N = a.length() - 1;
     int M = b.length() - 1;

     int carry = 0;
     string ans;

    while(N >= 0 || M >= 0|| carry)
    {
        if (N >= 0){
            carry += a[N--] - '0';
        }
        if (M >= 0){
            carry += b[M--] - '0';
        }
        ans += carry % 2 + '0';
        carry /=2;
    }

    reverse(begin(ans), end(ans));
    return ans;
    }
};
```