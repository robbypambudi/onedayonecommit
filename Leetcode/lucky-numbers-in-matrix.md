
```cpp
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> minRows(rows, INT_MAX);
        vector<int> maxCols(cols, 0);

        // Min in Colom
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                int element = matrix[i][j];
                minRows[i] = min(minRows[i], element);
                maxCols[j] = max(maxCols[j], element);
            }
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                int e = matrix[i][j];
                if (e == minRows[i] && e == maxCols[j]){
                    return {e};
                }
            }
        }
        return {};
    }
};
```