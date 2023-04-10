#include<iostream>
using namespace std;

    char getMaxOccuringChar(string str)
    {

        int arr[26]= {0};
        for(int i=0;i<str.length();i++){
            int n=0;
            char ch = str[i];
            if(ch>='a' && ch<='z'){
                n= ch-'a';
            }
            else{
                n= ch-'A';
            }
            arr[n]++;
        }
        int ans;
        int maxi= INT_MIN;
        for(int i=0;i<26;i++){
            if(maxi<arr[i]){
                ans= i;
                maxi=arr[i];
            }
        }
        char f= ans+'a';
        return f;
    }