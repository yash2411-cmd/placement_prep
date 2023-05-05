#include<bits/stdc++.h>
using namespace std;

    int maxVowels(string s, int k) {
        int count=0;
        unordered_set<char> vowels{'a','e','i','o','u'};
        for(int i=0;i<k;i++){
            count+= vowels.count(s[i]); // counting the vowels in a window size
        }
        int result= count;
        // moving window and keeping track of added char if its vowels or not
        for(int i=k;i<s.length();i++){
            count+= vowels.count(s[i])- vowels.count(s[i-k]);
            result= max(count,result);
        }
        return result;
    }

int main()
{
    string s= "abciiidef";
    int k=3;
    cout<<maxVowels(s,k);
 return 0;
}