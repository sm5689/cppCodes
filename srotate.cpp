#include<iostream>
using namespace std;

int main()
{
    string a,b,temp;
    cin>>a;
    cout<<a;
    cin>>b;
    temp = a+a;
    if(temp.find(b)<a.length())
    {cout<<"yes";}
    else
    {
        cout<<"no";
    }
    
    return 0;
}