# Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings. 

If there is no common prefix, return an empty string "".

## Approach
1. Find the shortest string in the array.
2. Iterate over the shortest string and compare each character with the corresponding character of all the strings in the array.
3. If any character does not match, return the prefix till that character.
4. If all characters match, return the shortest string.

## Implementation

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string shortesString = *min_element(strs.begin(), strs.end(), [](const string &a, const string &b){
            return a.size() < b.size();}
        );
        
        for (int i = 0; i < shortesString.size(); i++) {
            for (const string& str: strs) {
                if (str[i] != shortesString[i]) return shortesString.substr(0, i);
            }
        }
        return shortesString;

    }
};
```

## Details
```cpp
string shortesString = *min_element(strs.begin(), strs.end(), [](const string &a, const string &b){
            return a.size() < b.size();}
        );
```
- Find the shortest string in the array using `min_element` function.
- The lambda function passed to `min_element` compares the size of two strings and returns the one with the smaller size.
- Lamda function is a shorthand way to define a function in C++.

```cpp
for (int i = 0; i < shortesString.size(); i++) {
            for (const string& str: strs) {
                if (str[i] != shortesString[i]) return shortesString.substr(0, i);
            }
        }
```

