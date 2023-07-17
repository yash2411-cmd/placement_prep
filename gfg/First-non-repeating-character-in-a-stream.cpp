// Given an input stream A of n characters consisting only of lowercase alphabets. 
// While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. 
// If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear.
// If there is no such character then append '#' to the answer.


// example
// Input: A = "aabc"
// Output: "a#bb"
// Explanation: For every character first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - first non-repeating character is 'b'

#include<bits/stdc++.h>
using namespace std;

// solution using queue
string FirstNonRepeating(string A){
		    // Code here
		    vector<int>arr(26,0);
		    string ans="";
		    queue<char>q;
		    for(int i=0;i<A.size();i++){
		        arr[A[i]-'a']++;
		        q.push(A[i]);
		        while(!q.empty() && arr[q.front()-'a']>1){
		            q.pop();
		        }
		        if(q.empty()){
		            ans+='#';
		        }
		        else{
		            ans+= q.front();
		        }
		    }
		    return ans;
		}

int main()
{
 return 0;
}


