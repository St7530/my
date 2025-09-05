#include <iostream>
#include <string>
using namespace std;

string itob(int n,int b) {
    bool isNegative=false;
    if (n<0)
    {
        isNegative=true;
        n=-n;
    }
    
    int count=0;
    int n_=n;
    // Calculate count
    for(int i=0;n_>0;i++)
    {
        n_%b;
        count++;
        n_/=b;
    }

    string a[count];
    int num;
    for(int i=0;n>0;i++)
    {
        num=n%b;
        if (num<10)
        {
            a[i]=char(num+48);
        }
        else
            a[i]=char(num+87);
        n/=b;
    }

    // Output
    string str="";
    if (isNegative)
        str+="-";
    for(int i=count-1;i>=0;i--)
    {
        str+=a[i];
    }
    return str;
}

int main() {
    int n,b;
    cin>>n>>b;
    string str=itob(n,b);
    cout<<str;
    return 0;
}



