# Robot Collisions 

## Problem Statement
[Leetcode](https://leetcode.com/problems/robot-collisions)

## Approach
1. Get the index of the robots and save to the `indices` vector.
2. Sort the `indices` vector based on the positions of the robots.
-   There we use lambda function to compare the positions of the robots.
-   `[&] (int left, int right) { return positions[left] < positions[right]; }` is used to compare the positions of the robots, so the result will be sorted base on the postions of the robots.
3. Iterate over the `indices` vector.
4. If the direction of the robot is 'R', push the index of the robot to the stack.
5. If the direction of the robot is 'L', check if the stack is not empty and the health of the current robot is greater than 0.
6. If the health of the top robot in the stack is greater than the health of the current robot, decrement the health of the top robot and set the current robot health to 0.
7. If the health of the top robot in the stack is less than the health of the current robot, decrement the health of the top robot and set the health of the current robot to 0.
8. If the health of the top robot in the stack is equal to the health of the current robot, set both the health of the top robot and the health of the current robot to 0.
9. Iterate over the healths vector and push the health of the robots that are greater than 0 to the result vector.
## Code 

```cpp
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {

        int n = positions.size();
        vector<int> indices(n), result;
        stack <int> stack;

        for (int index = 0; index < n; ++index) {
            indices[index] = index;
        }

        iota(indices.begin(), indices.end(), 0);


        for (int currentIndex : indices){
            if (directions[currentIndex] == 'R'){
                stack.push(currentIndex);
            }
            else {
                while(!stack.empty() && healths[currentIndex] > 0){
                    int topIndex = stack.top();
                    stack.pop();

                    if (healths[topIndex] > healths[currentIndex]){
                        healths[topIndex] -=1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]){
                        healths[topIndex] = 0;
                        healths[currentIndex] -=1;
                    }
                    else {
                        healths[topIndex] = 0;
                        healths[currentIndex] = 0;
                    }

                }
            }
        }
        
        for (int currentHealth : healths){
            if (currentHealth > 0){
                result.push_back(currentHealth);
            }
        }
        return result;
    }
};
```

## Reference
- Editorial Leetcode