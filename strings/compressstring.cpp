#include<bits/stdc++.h>
using namespace std;
    int compress(vector<char>& chars) {
        int i=0;
        int ansind=0;
        int n= chars.size();
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            chars[ansind++]= chars[i];
            int count= j-i;
            if(count>1){
                string c= to_string(count);
                for(char ch:c){
                    chars[ansind++]=ch;
                }
            }
            i=j;
        }
        return ansind;
    }
