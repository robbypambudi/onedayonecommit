/**
 * Two Sum
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 * Complexity Analysis: O(n)
 *
 * Approach: Hash Table
 *
 * 1. Create a hash table to store the elements of the array.
 * 2. Iterate through the array and check if the target - nums[i] is present in the hash table.
 * 3. If it is present, return the indices of the two numbers, 'umap[i]' and 'i'.
 * 4. if not present in the hash table add the element to the hash table.
 * 5. If no such pair is found, throw an exception.
 *
 * Note:
 * - umap.cend is used to check if the element is the end of the hash table.
 * - umap.find() is used to find the element in the hash table, and save in the iterator 'it' variable.
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> umap;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // calculate
            if (const auto it = umap.find(target - nums[i]); it != umap.cend())
            {
                cout << it->first;
                return {it->second, i};
            }
            else
            {
                umap[nums[i]] = i;
            }
        }
        throw;
    }
};