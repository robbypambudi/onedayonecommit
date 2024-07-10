# Add Two Numbers

## Problem
[Link](https://leetcode.com/problems/add-two-numbers)

## Approach
1. Initialize a dummy node to store the sum of the two numbers.
2. Initialize a current node to keep track of the current node in the linkedlist
3. Initialize a flag to store the carry.
4. Iterate over the linkedlist until both the linkedlists are not empty and the carry is not zero.
5. Add the values of the two nodes and the carry.
6. Update the carry and the current node.
7. If the linkedlist is not empty, move to the next node.
8. Return the next node of the dummy node.

## Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int flag = 0;
    
        while(l1 != nullptr || l2 != nullptr || flag != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            int total = val1 + val2+ flag;
            flag = total / 10;
            total = total % 10;

            current->next = new ListNode(total);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return dummy->next;
        
    }
};
```