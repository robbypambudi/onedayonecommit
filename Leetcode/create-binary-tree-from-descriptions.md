# Create Binary Tree from Descriptions

## Problem Statement
[Leetcode](https://leetcode.com/problems/create-binary-tree-from-descriptions)

## Approach
> Use a map to store the nodes and a set to store the children. Iterate over the descriptions and create the binary tree.

1. Create a map to store the nodes and a set to store the children.
2. Create a tree and store the parent and child nodes in the map.
3. Iterate over the map and return the root node.
4. If the child is not in the set, return the node.


```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map <int, TreeNode*> nodeMap;
        unordered_set <int> children;

        for (const auto& description: descriptions){
            int parentValue = description[0];
            int childValue = description[1];
            bool isLeft = description[2];

            if (nodeMap.count(parentValue) == 0) {
                nodeMap[parentValue] = new TreeNode(parentValue);
            }
            if (nodeMap.count(childValue) == 0){
                nodeMap[childValue] = new TreeNode(childValue);
            }

            if (isLeft){
                nodeMap[parentValue]->left = nodeMap[childValue];
            }
            else {
                nodeMap[parentValue]->right = nodeMap[childValue];
            }

            children.insert(childValue);
        }

        for (auto &entry: nodeMap){
            int value = entry.first;
            TreeNode* node = entry.second;
            if (children.find(value) == children.end()){
                return node;
            }
        }
        return nullptr;
    }
};
```