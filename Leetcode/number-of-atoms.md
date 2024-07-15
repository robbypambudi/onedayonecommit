# Number Of Atoms

## Problem
[Link](https://leetcode.com/problems/number-of-atoms)

## Approach
1. Parse the formula using a recursive approach.
2. Initialize a variable to keep track of the index.
3. Iterate over the formula until the end of the formula.

```cpp
class Solution {
int index = 0;
public:
    string countOfAtoms(string formula) {
        unordered_map<string, int> counts = parse(formula);
        string result;
        vector<pair<string, int>> elements(counts.begin(), counts.end());
        sort(elements.begin(), elements.end());

        for (const auto& [element, count] : elements) {
            result += element;
            if (count > 1) result += to_string(count);
        }

        return result;
    }

    unordered_map<string, int> parse(string& formula) {
        unordered_map<string, int> counts;
        int n = formula.size();
        while (index < n && formula[index] != ')') {
            if (formula[index] == '(') {
                index++;
                unordered_map<string, int> subCounts = parse(formula);
                index++;
                int multiplier = parseNumber(formula);

                for (auto& [element, count] : subCounts) {
                    counts[element] += count * multiplier;
                }
            } else {
                string element = parseElement(formula);
                int count = parseNumber(formula);
                counts[element] += count;
            }
        }

        return counts;
    }

    string parseElement(string& formula) {
        string element;
        element += formula[index++];
        while (index < formula.size() && islower(formula[index])) {
            element += formula[index++];
        }
        return element;
    }

    int parseNumber(string& formula) {
        int number = 0;
        while (index < formula.size() && isdigit(formula[index])) {
            number = number * 10 + (formula[index++] - '0');
        }
        return number == 0 ? 1 : number;
    }
};
```