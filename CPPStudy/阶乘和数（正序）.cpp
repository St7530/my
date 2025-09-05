//阶乘和数（正序）
#include <iostream>
#include <cmath>
using namespace std;

int fac(int a) {    // 阶乘
    int sum=1;
    for (int i = 1; i <= a; i++)
    {
        sum*=i;
    }
    return sum;
}

int main() {
    int n,d,s,sum=0;
    cin>>n;
    cout<<n<<",";

    // Get Digit
    for (int i = 1;; i++)
    {
        if (n<(int)pow(10,i))
        {
            d=i;
            break;
        }    
    }
    
    for (int i = 1; i <= d; i++)
    {
        s=n/(int)pow(10,d-i)%10;
        cout<<s<<"!";
        if (i<d)
        {
            cout<<"+";
        }
        sum+=fac(s);
    }
    cout<<"="<<sum<<endl;
    if (sum==n)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}