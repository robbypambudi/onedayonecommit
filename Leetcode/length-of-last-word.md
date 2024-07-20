```cpp
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int N = s.size();

        int length = 0;
        for (int i = N; i >= 0; i--)
        {
            if (s[i] == ' ' && length > 0)
            {
                break;
            }
            if (s[i] - 'A' < 0)
            {
                continue;
            }
            else
            {
                length += 1;
            }
        }
        return length - 1;
    }
};
```