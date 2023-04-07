#include<bits/stdc++.h>
using namespace std;
// O(n) tc and O(n) sc

    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>s;
        unordered_set<int>d;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(int j=0;j<arr.size();j++){
            s.insert(arr[j]);
        }
        for(auto i:mp){
            d.insert(i.second);
        }
        if(s.size()==d.size())return true;
        else return false;

    }

    int main(){
        vector<int>v= {1,2,2,1,1,3,3};
        cout<<uniqueOccurrences(v);
        return 0;

    }