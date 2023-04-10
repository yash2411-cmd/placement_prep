#include<bits/stdc++.h>
using namespace std;

    bool charequal(int a[26],int b[26]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return 0;
            }
        }
        return 1;
    }

    bool checkInclusion(string s1, string s2) {
        int count1[26]= {0};
        for(int i=0;i<s1.length();i++){
            count1[s1[i]-'a']++;
        }
        int i=0;
        int count2[26]= {0};
        int win= s1.length();
        while(i<win && i<s2.length()){
            int ch= s2[i]-'a';
            count2[ch]++;
            i++;
        }
        if(charequal(count1,count2)){
            return 1;
        }
        while(i<s2.length()){
            int newch= s2[i]-'a';
            count2[newch]++;
            int oldch= s2[i-win]-'a';
            count2[oldch]--;
            i++;
        if(charequal(count1,count2)){
            return 1;
        }

        }
        return 0;
    }
