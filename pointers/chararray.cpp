#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    char ch[6]= "abcde";

    cout<<arr<<endl;
    cout<<ch<<endl;

    char *p= &ch[0];
    cout<<p<<endl;

    char temp= 'z';
    char *pt= &temp;
    cout<<pt<<endl;

 return 0;
}