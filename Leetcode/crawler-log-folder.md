# Crawler Log Folder

You are a file system crawler, and you are given a folder path, from the root folder to the target folder. You are given a list of strings `logs` where `logs[i]` is the path of the `ith` file in the folder.

The file system only supports the following operations:

- `"./"`: Move to the same folder.
- `"../"`: Move to the parent folder.
- `"x/"`: Move to the child folder named `x`.

# Approach
1. Initialize a queue `qlogs` to store the folder paths.
2. Iterate over the `logs` array
3. If the current folder path is `"../"`, check if the queue is empty. If not, pop the top element from the queue.
4. If the current folder path is `"./"`, continue to the next iteration.
5. If the current folder path is a child folder, push the folder path to the queue.
6. Return the size of the queue as the minimum number of operations required to reach the target folder.


```cpp
class Solution {

public:
    int minOperations(vector<string>& logs) {
        queue <string> qlogs;

        for (int i = 0; i < logs.size(); i++){
            if (logs[i] == "../"){
                if (qlogs.empty()){
                    continue;
                }
                qlogs.pop();
            }
            else if (logs[i] == "./") continue;
            else {
                qlogs.push(logs[i]);
            }
        }
        return qlogs.size();
    }
};
```