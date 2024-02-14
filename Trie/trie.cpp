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

class trie
{
public:
    TrieNode *root;

    // constructor
    trie()
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
        int index = word[0] - 'A';
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

    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    trie *t = new trie();
    // trie t;
    t->insertword("ABCD");
    if (t->search("ABCD"))
        cout << "Present" << endl;
    else
    {
        cout << "NOT found" << endl;
    }
    return 0;
}