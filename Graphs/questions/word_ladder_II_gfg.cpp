#include <bits/stdc++.h>
using namespace std;

// to pridict time complexity  of this solution is pretty much impossible and the same code doesn't work for leetcode
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        // we need to maintain a usedword list at current level so that we know which all words are used till now
        vector<string> used;
        used.push_back(beginWord);
        int lvl = 0;

        while (!q.empty())
        {
            vector<string> temp = q.front();
            q.pop();
            // temp is the level 1 sequence and lvl zero is used
            if (temp.size() > lvl)
            {
                // this means we have entered a new level so we can remove the used words from set and increase the lvl
                lvl++;
                for (auto i : used)
                {
                    s.erase(i);
                }
            }

            string word = temp.back();
            if (word == endWord)
            {
                // first sequence where we reached the end
                if (ans.size() == 0)
                {
                    ans.push_back(temp);
                }
                // if we have a sequence so we only need those who are of the same length
                else if (ans[0].size() == temp.size())
                {
                    ans.push_back(temp);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                // changing the value of the word
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (s.find(word) != s.end())
                    {
                        // we push the new word to the sequnce
                        temp.push_back(word);
                        // store the new sequence in the queue
                        q.push(temp);
                        // store the new word that is used on this level
                        used.push_back(word);
                        // delete the word after its pushed to queue beacuse next time we need a new sequence from the previous word and we need the length to be same
                        temp.pop_back();
                    }
                }
                // make sure to change the char to original char after each iteration
                word[i] = original;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}