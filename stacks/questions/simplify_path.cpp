#include <bits/stdc++.h>
using namespace std;
// Initialize an empty stack to keep track of directories.
// Split the input path by '/' to get individual components.
// Iterate over the components:
// If the component is an empty string or '.', skip it.
// If the component is '..', pop the top directory from the stack if it's not empty (to move up one level).
// Otherwise, push the component onto the stack.
// After processing all components, construct the simplified canonical path by joining the directories in the stack with '/'.
// Prepend a single '/' to the constructed path to ensure it starts with a slash.
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> st;
        stringstream stream(path);
        string dir;

        while (getline(stream, dir, '/'))
        {
            // ignore the " " and . if any
            if (dir == "" || dir == ".")
            {
                continue;
            }
            // handling the .. case sepraterly to move up one directory
            else if (dir == "..")
            {
                if (!st.empty())
                {
                    st.pop_back();
                }
            }
            else
            {
                st.push_back(dir);
            }
        }
        string ans;
        for (auto &i : st)
        {
            ans += "/" + i;
        }
        return ans.empty() ? "/" : ans;
    }
};

int main()
{
    return 0;
}