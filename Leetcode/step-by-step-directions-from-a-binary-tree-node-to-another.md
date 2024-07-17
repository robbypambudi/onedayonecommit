# Step-by-step Directions from a Binary Tree Node to Another

## Problem
[Leetcode](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)

## Approach
1. Find the paths from the root to the start and destination nodes.
2. Find the common ancestor of the start and destination nodes.
3. Add "U" for each step from startPath, and substraction with the common ancestor to get the minimum steps to reach the destination node.
4. Add the directions from the common ancestor to the destination node. which is already calculated in the destination path.

```cpp
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;

        // Find paths from root to start and destination nodes
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        string directions;
        int commonPathLength = 0;

        // Find the length of the common path
        // Why do we need to find the common path?
        // To find the common ancestor of the start and destination nodes
        while (commonPathLength < startPath.length() &&
               commonPathLength < destPath.length() &&
               startPath[commonPathLength] == destPath[commonPathLength]) {
            commonPathLength++;
        }

        // Add "U" for each step to go up from start to common ancestor
        for (int i = 0; i < startPath.length() - commonPathLength; i++) {
            directions += "U";
        }

        // Add directions from common ancestor to destination
        for (int i = commonPathLength; i < destPath.length(); i++) {
            directions += destPath[i];
        }

        return directions;
    }

private:
    bool findPath(TreeNode* node, int target, string& path) {
        if (node == nullptr) {
            return false;
        }

        if (node->val == target) {
            return true;
        }

        // Try left subtree
        path += "L";
        if (findPath(node->left, target, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        // Try right subtree
        path += "R";
        if (findPath(node->right, target, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        return false;
    }
};
```

## References
- Editorial Leetcode