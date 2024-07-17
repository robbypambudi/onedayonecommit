# Longest Palindromic Substring

[Leetcode](https://leetcode.com/problems/longest-palindromic-substring/)

## Approach
> Dynamic Programming

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        array<int, 2> result = {0, 0};

        // precondition
        for (int i = 0; i<n; i++){
            dp[i][i] = 1;
        }

        // precondition
        for(int i = 0; i < n -1; i++){
            if (s[i] == s[i +1]){
                dp[i][i+1] = 1;
                result = {i, i+1};
            }
        }

        for (int diff = 2; diff < n; diff++){
            for (int i = 0; i < n - diff; i++){
                int j = i + diff;
                if (s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                    result = {i, j};
                }
            }
        }

        return s.substr(result[0], result[1] - result[0] + 1);
    }
};
```