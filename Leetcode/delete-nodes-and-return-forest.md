# Delete Nodes And Return Forest

## Problem
[Leetcode](https://leetcode.com/problems/delete-nodes-and-return-forest/)

## Approach
> Using Recursion to traverse the tree and delete the nodes.
1. Create a set of nodes to delete.
2. Recursively traverse the tree and delete the nodes.
3. If the current node is in the set of nodes to delete, add its children to the result and delete the node.
4. Return the node to the parent.

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;  
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());

        root = removeNodes(root, to_delete_set, result);

        if (root != nullptr){
            result.push_back(root);
        }
        return result;
        
    }

    TreeNode* removeNodes(TreeNode* node, unordered_set<int> &to_delete_set, vector<TreeNode*> &result){
        if (node == nullptr){
            return nullptr;
        }

        node->left = removeNodes(node->left, to_delete_set, result);
        node->right = removeNodes(node->right, to_delete_set, result);

        if (to_delete_set.find(node->val) != to_delete_set.end()){
            if (node->left != nullptr){
                result.push_back(node->left);
            }
            if (node->right != nullptr){
                result.push_back(node->right);
            }
            delete node;
            return nullptr;
        }    

        return node;
    }
};
```