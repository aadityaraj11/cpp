#include<iostream>
using namespace std;
void solve(string digit , string output,int index , string &ans, string mapping[])
{
    // base case 
    if(index>digit.length())
    {
        ans=output;
        return;
    }
    int number =digit[index]-'0';
    string value=mapping[number];
    for(int i=0;i<value.length();i++)
    {
        output=value[i];
        solve(digit,output,index+1,ans,mapping);
        output='\0';
    }
}
int main()
{
    string ans;
    string  mapping[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output ="";
    int index=0;
    string digits ;
    cout<<"enter digit"<<endl;
    cin>>digits;
    solve(digits,output,index,ans,mapping);
    return 0;
}