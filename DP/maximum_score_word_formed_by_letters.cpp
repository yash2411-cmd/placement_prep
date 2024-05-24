#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculateWordScore(const string &word, const vector<int> &score)
    {
        int wordScore = 0;
        for (char c : word)
        {
            wordScore += score[c - 'a'];
        }
        return wordScore;
    }

    // Function to check if a word can be formed with the available letters
    bool canFormWord(const string &word,
                     unordered_map<char, int> &lettersCount)
    {
        unordered_map<char, int> wordCount;
        for (char c : word)
        {
            wordCount[c]++;
            if (wordCount[c] > lettersCount[c])
            {
                return false;
            }
        }
        return true;
    }

    // Backtracking function to find the maximum score
    void backtrack(const vector<string> &words, const vector<int> &score,
                   unordered_map<char, int> &lettersCount, int index,
                   int currentScore, int &maxScore)
    {
        if (index == words.size())
        {
            maxScore = max(maxScore, currentScore);
            return;
        }

        // Option 1: Skip the current word
        backtrack(words, score, lettersCount, index + 1, currentScore,
                  maxScore);

        // Option 2: Include the current word if possible
        if (canFormWord(words[index], lettersCount))
        {
            // Deduct letters count
            for (char c : words[index])
            {
                lettersCount[c]--;
            }

            // Include current word's score and proceed
            backtrack(words, score, lettersCount, index + 1,
                      currentScore + calculateWordScore(words[index], score),
                      maxScore);

            // Restore letters count (backtrack)
            for (char c : words[index])
            {
                lettersCount[c]++;
            }
        }
    }
    int maxScoreWords(vector<string> &words, vector<char> &letters,
                      vector<int> &score)
    {
        unordered_map<char, int> lettersCount;
        for (char c : letters)
        {
            lettersCount[c]++;
        }

        int maxScore = 0;
        backtrack(words, score, lettersCount, 0, 0, maxScore);

        return maxScore;
    }
};

int main()
{
    return 0;
}