#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // create a set to make sure that we can search and remove in good time compx
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        int ans = 0;
        // time complexity and space is O(length of temp * 26) + O(n) = O(n*temp-length*26)
        while (!q.empty())
        {
            string temp = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if (temp == endWord)
            {
                ans = lvl;
                break;
            }

            for (int i = 0; i < temp.size(); i++)
            {
                // the char we want to change
                char original = temp[i];
                // changing the value of the word
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    temp[i] = ch;
                    if (s.find(temp) != s.end())
                    {
                        s.erase(temp);
                        q.push({temp, lvl + 1});
                    }
                }
                // make sure to change the char to original char after each iteration
                temp[i] = original;
            }

            // check if we have arrived at the end word save the level and return it.
        }
        return ans;
    }
};

int main()
{
    return 0;
}