//逆序乘积式
#include <iostream>
#include <cmath>
using namespace std;
int Reverse(int a);

int main() {
    int a,b,an,bn;
    cin>>a>>b;
    an=Reverse(a);
    bn=Reverse(b);
    cout<<a<<"*"<<b;
    if (a*b==an*bn)
        cout<<"=";
    else
        cout<<"!=";
    cout<<an<<"*"<<bn;
    return 0;
}

int Reverse(int a) {
    int d,s,sum=0;
    // Get Digit
    for (int i = 1;; i++)
    {
        if (a<(int)pow(10,i))
        {
            d=i;
            break;
        }    
    }
    // Get Reverse
    for (int i = 1; i <= d; i++)
    {
        s=a/(int)pow(10,i-1)%10;
        sum+=s*(int)pow(10,d-i);
    }
    return sum;
}