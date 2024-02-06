#include <bits/stdc++.h>
using namespace std;

// static int speedup = []() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	cout.tie(0);
// 	return 0;
// }();
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    { // creating a ans vector
        vector<vector<string>> group;
        // creating a mapping for each string to the groups of anagrams
        unordered_map<string, vector<string>> anagrams;
        for (auto &word : strs)
        { // for each sorted word we are storing the mapping  in 'anagrams'
            string sortword = word;
            sort(sortword.begin(), sortword.end());
            anagrams[sortword].push_back(word);
        }
        // simply pushing the anagrams vector in the ans vector.
        for (auto &i : anagrams)
        {
            group.push_back(i.second);
        }
        return group;
    }
};

int main()
{
    return 0;
}