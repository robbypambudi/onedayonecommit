# ZigZag Conversion

## Problem
[Leetcode](https://leetcode.com/problems/zigzag-conversion/)

## Approach
1. Create a vector of strings to store the result.
2. If the string has only one character or the number of rows is 1, return the string.
3. Iterate over the string and add characters to the result vector.
4. Change the direction of the index when it reaches the top or bottom row.
5. Concatenate the strings in the result vector and return the final result.

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> result(numRows);

        if (s.size() == 1 || numRows == 1){
            return s;
        }
        int index = 0;
        int flag = 1;
        for (char c: s){
            result[index].push_back(c);
            if (index == numRows -1 ){
                flag = -1;
            }
            else if (index == 0){
                flag = 1;
            }
            index +=flag;
        }

        string finalResult;
        for (int i = 0; i < numRows; i++){
            finalResult += result[i];
        }
        return finalResult;
    }
};
```