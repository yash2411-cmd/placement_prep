#include <bits/stdc++.h> 

void solve(string str, string output, int i, vector<string>& ans){
	if(i>=str.length()){
		if(output.length()>0){
		ans.push_back(output);

		}
		return;
	}
	// exclude ki call maar do 
	solve(str,output, i+1, ans);

	// include ki call mardo 
	char ch= str[i];
	output.push_back(ch);
	solve(str, output, i+1, ans);
}

vector<string> subsequences(string str){
	
	// Write your code here
	vector<string> ans;
	string output= "";
	int i=0;
	solve(str, output, i, ans);
	return ans;
	
}
