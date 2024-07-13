# Maximum Score From Removing Substrings

[Leetcode](https://leetcode.com/problems/maximum-score-from-removing-substrings/)

## Approach
> Gready Approach

1. We asume that x is greater than y. If it is not, we swap x and y and reverse the string. Its trick to make sure that "ab" is more valuable than "ba".
2. Iterate over the string and count the number of 'a' and 'b' characters.
3. If we find 'a', we increment the count of 'a' characters.
4. If we find 'b', we check if we have any 'a' character there. If we have, we decrement the count of 'a' characters and add x to the total points, we do this because we have found a pair of "ab" which the point is 'x'.
5. If we find 'b' and we don't have any 'a' character, we increment the count of 'b' characters.
6. If we find any other character, we calculate the points of totalPoint by multiplying the minimum of aCount and bCount by y. Why we do this? Because we have found a pair of "ba" which the point is 'y'.
7. Finally, we calculate the points of totalPoint by multiplying the minimum of aCount and bCount by y.
8. Return the total points. 


## Code 
```cpp
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y){
            int temp = y;
            y = x;
            x = temp;
            reverse(s.begin(), s.end());
        }
        
        int aCount = 0, bCount = 0, totalPoints = 0;

        for (char c : s){
            if (c == 'a'){
                aCount +=1;
            }
            else if (c == 'b'){
                if (aCount > 0){
                    aCount -=1;
                    totalPoints += x;
                }
                else {
                    bCount +=1;
                }
            }
            else {
                totalPoints += min(aCount, bCount) * y;
                aCount = bCount = 0;
            }
        }
        totalPoints += min(aCount, bCount) * y;
        return totalPoints;
    }
};
```








## Reference
- Editorial Leetcode