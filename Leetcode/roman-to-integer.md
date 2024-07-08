# Roman to Integer

## Problem:
[Link](https://leetcode.com/problems/roman-to-integer)

## Solution (Naive):
1. Create a map of roman characters `<char, int>` and initialize it with the values.
2. Loop through the string.
3. Check if the current character is 'I' and the next character is 'V' or 'X'.
    1. Subtract 1 from the result.
    2. Add the value of the next character to the result.
    3. Skip the next character.
4. Likewise, check for 'X' and 'L' or 'C', and 'C' and 'D' or 'M'.
5. Add the value of the current character to the result.

## Code 
````cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> roman = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000},
        };

        int skipFlag = false;
        int result = 0;

        for (int i = 0; i < s.length(); i++){
            if (skipFlag) {
                skipFlag = false;
                continue;
            }
            if (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
                skipFlag = true;
                result -=1;
                result += roman.at(s[i+1]);
                continue;
            }
            if (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
                skipFlag = true;
                result -=10;
                result += roman.at(s[i+1]);
                continue;
            }
            if (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
                skipFlag = true;
                result -=100;
                result += roman.at(s[i+1]);
                continue;
            }
            result += roman.at(s[i]);
        }
        return result;
    }
};
```

## Better Solution:
1. Create a map of roman characters `<char, int>` and initialize it with the values.
2. Loop through the string.
3. If the value of the current character is less than the value of the next character, subtract the value of the current character from the result.
4. Otherwise, add the value of the current character to the result.

## Code 
````cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> roman = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000},
        };

        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            if (roman[s[i]] < roman[s[i+1]])
                result -= roman[s[i]];
            else 
                result += roman[s[i]];
        }
        return result;
    }
};
```