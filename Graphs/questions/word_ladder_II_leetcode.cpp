#include <bits/stdc++.h>
using namespace std;
//  this version is optimized for leetcode testcases this is not the good practice to follow up in an interview
class Solution
{
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string &word, vector<string> &res)
    {
        if (word == b)
        {
            reverse(res.begin(), res.end());
            ans.push_back(res);
            // re-reverse the res to pop back
            reverse(res.begin(), res.end());
            return;
        }
        int sz = word.size();
        int step = mp[word];
        for (int i = 0; i < sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] + 1 == step)
                {
                    res.push_back(word);
                    dfs(word, res);
                    res.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<string> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        q.push(beginWord);
        s.erase(beginWord);
        b = beginWord;
        mp[beginWord] = 0;
        int si = beginWord.size();
        while (!q.empty())
        {
            string word = q.front();
            int lvl = mp[word];
            q.pop();
            if (word == endWord)
            {
                break;
            }
            for (int i = 0; i < si; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (s.find(word) != s.end())
                    {
                        q.push(word);
                        s.erase(word);
                        mp[word] = lvl + 1;
                    }
                }
                word[i] = original;
            }
        }
        if (mp.find(endWord) != mp.end())
        {
            vector<string> res;
            res.push_back(endWord);
            dfs(endWord, res);
        }
        return ans;
    }
};

int main()
{
    return 0;
}