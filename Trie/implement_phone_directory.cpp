#include <bits/stdc++.h>
using namespace std;

class TrieNode
{

public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    // constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    // constructor
    Trie()
    {
        root = new TrieNode('\0');
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
            root->children[index] = child;
        }

        // recursion smabhal lega
        insertUtil(child, word.substr(1));
    }

    void insertword(string word)
    {
        insertUtil(root, word);
    }

    void print(TrieNode *curr, vector<string> &temp, string prefix)
    {

        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                prefix.push_back(ch);
                // string newprefix = prefix+ch;
                print(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getsuggestion(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> ans;
        string prefix = "";
        // TrieNode* curr = NULL;

        for (int i = 0; i < str.length(); i++)
        {
            char last_ch = str[i];
            prefix.push_back(last_ch);

            TrieNode *curr = prev->children[last_ch - 'a'];

            if (curr == NULL)
            {
                break;
            }

            vector<string> temp;
            print(curr, temp, prefix);
            ans.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *t = new Trie();

    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertword(str);
    }

    return t->getsuggestion(queryStr);
}

int main()
{
    return 0;
}