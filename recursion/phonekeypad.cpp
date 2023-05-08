#include<bits/stdc++.h>
using namespace std;

    void solve(string digits, string output, int index, vector<string>& ans, string map[]){

        // base case 
        if(index>= digits.size()){
            ans.push_back(output);
            return;
        }
        // getting the number from input string
        int num= digits[index]-'0';
        // getting value mapped to the given input number
        string val= map[num];
        // looping on mapped value like "abc"
        for(int i=0;i<val.length();i++){
            output.push_back(val[i]); // pushing for each case like a, then b and so on
            solve(digits, output, index+1, ans, map); // calling function for next value b
            output.pop_back(); // making sure to backtrack and delete the extra a added to the output initally
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output="";
        int index=0;
        if(digits.length()==0){
            return ans;
        }
        string map[10]= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, map);
        return ans;
    }

int main()
{
    string s;
    cin>>s;
    vector<string> res;
    res=letterCombinations(s);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
 return 0;
}