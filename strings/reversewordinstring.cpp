#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    size_t start = s.find_first_not_of(" ");
    size_t end = s.find_last_not_of(" ");
    s = s.substr(start, end - start + 1);
    string word;

    vector<string> words;
    
    // extract words from input string and store them in a vector
    for (int i=0;i<s.length();i++) {
        if (s[i] == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
            // skip any extra spaces
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            i--;  // backtrack to the last space
        } else {
            word += s[i];
        }
    }
    words.push_back(word);  // push last word to the vector
    
    string output;
    for (int i = words.size() - 1; i >= 0; i--) {
        output += words[i] + " ";
    }
    output.pop_back();  // remove last space from the output string
    
    // cout << output << endl;  // output the reversed string
    
    return output;
    }

    
