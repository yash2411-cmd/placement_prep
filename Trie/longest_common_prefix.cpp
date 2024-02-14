#include <bits/stdc++.h>
using namespace std;

// normal solution TC = O(length of string * number of string), SC = O(length of string)
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans;
        for (int i = 0; i < strs[0].length(); i++)
        {
            char ch = strs[0][i];
            bool match = true;

            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j].length() < i || ch != strs[j][i])
                {
                    match = false;
                    break;
                }
            }
            if (match == false)
            {
                break;
            }
            else
            {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};

// using trie TC = O(length of string * number of string), SC = O(length of string * number of string)
class TrieNode
{

public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    // constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class trie
{
public:
    TrieNode *root;

    // constructor
    trie(char ch)
    {
        root = new TrieNode(ch);
    }
    // utility function for inserting word by recursion
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assuming that capital chars are there
        int index = word[0] - 'a';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            // move ahead  in the current word and recurse
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion smabhal lega
        insertUtil(child, word.substr(1));
    }

    void insertword(string word)
    {
        insertUtil(root, word);
    }

    void LCP(string str, string &ans)
    {
        TrieNode *temp = root;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (temp->childCount == 1 && !temp->isTerminal)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                temp = temp->children[index];
            }
            else
            {
                break;
            }
        }
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        trie *t = new trie('\0');

        for (int i = 0; i < strs.size(); i++)
        {
            t->insertword(strs[i]);
        }
        string first = strs[0];
        string ans;
        t->LCP(first, ans);
        return ans;
    }
};

// third solution  TC=  O(n * m * log(n)), SC = O(M+N), where m is length of string and n is number of strings
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0], last = strs[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
                return ans;
            ans = ans + first[i];
        }
        return ans;
    }
};

int main()
{
    return 0;
}