#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    map<char,int>count;
		    queue<char>q;
		    string ans= "";
		    
		    for(int i=0;i<A.size();i++){
		        char ch= A[i];
		        count[ch]++;
		        q.push(ch);
		    }
		    while(!q.empty()){
		        if(count[q.front()]>1){
		            q.pop();
		        }
		        else{
		            ans.push_back(q.front());
		            break;
		        }
		    }
		    if(q.empty()){
		        ans.push_back('#');
		    }
		return ans; 
		}

};


/*
// second way
class Solution {
public:
    int firstUniqChar(string s) {
        
        queue<int>q;
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            char ch= s[i];
            q.push(i);
            arr[ch-'a']++;
            while(!q.empty()){
                if(arr[s[q.front()]-'a']>1){
                    q.pop();
                }
                else{
                    break;
                }
            }
        }
        if(!q.empty()){
            return q.front();
        }
        else{
            return -1;
        }
        
    }
};

// third way
class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
        
    }
};




*/



int main()
{
 return 0;
}