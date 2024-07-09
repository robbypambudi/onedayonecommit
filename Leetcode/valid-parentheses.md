# Valid Parentheses
## Description
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

## Approach
1. Use a stack to store the opening brackets. Why? because stack follows LIFO (Last in First Out) order.
2. Iterate over the string.
3. If the character is an opening bracket, push it to the stack.
4. If the character is a closing bracket, check if the stack is empty. If it is, return false. 
5. If the stack is not empty, check if the top of the stack is the corresponding opening bracket. If it is, pop the top of the stack.
6. If the stack is empty after the iteration, return true. Else, return false.

## Implementation
```cpp
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (char& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            }

            if (c == ')' || c == ']' || c == '}') {
                if (stack.empty()) {
                    return false;
                }
                char tag = stack.top();
                if (tag == '(' && c != ')') {
                    return false;
                } else if (tag == '[' && c != ']') {
                    return false;
                } else if (tag == '{' && c != '}') {
                    return false;
                }
                stack.pop();
            }
        }

        if (!stack.empty()) {
            return false;
        }

        return true;
    }
};
```