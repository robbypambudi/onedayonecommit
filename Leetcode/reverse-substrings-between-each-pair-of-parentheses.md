# Reverse Substrings Between Each Pair of Parentheses

## Problem
[Link](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses)

## Approach
1. Using a recursive approach to solve the problem.
2. Initialize a variable to keep track of the same index.
3. Iterate over the string until the end of the string.
4. If the character is a closing parenthesis, return the reversed string.
5. If the character is an opening parenthesis, call the helper function recursively.
6. If the character is not a parenthesis, add the character to the result.
7. Return the result.

## Code 
```cpp
class Solution {
int i = 0;
public:
    string reverseParentheses(string s) {
        return helper(s);
    }

    string helper(string& s){
        string result;

        while(i< s.length()){
            if (s[i] == ')'){
                i++;
                reverse(result.begin(), result.end());
                return result;
            }
            else if (s[i] == '('){
                i++;
                string st = helper(s);
                result += st;
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};
``