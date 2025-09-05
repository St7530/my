//回文数A
#include <iostream>
#include <cmath>
using namespace std;

int GetDigit(int a) {
    for (int i = 1;; i++)
    {
        if (a<(int)pow(10,i))
        {
            return i;
        }    
    }
}

int GetOrder(int a,int i) {
    int d=GetDigit(a);
    return a/(int)pow(10,d-i)%10;
}

int main() {
    int a,b,d;
    cin>>a>>b;
    for (int i = a; i <= b; i++)    // 每个数
    {
        bool isSym=true;
        d=GetDigit(i);
        for (int j = 1; j <= d/2; j++)  // 每个数的每一位
        {
            if (GetOrder(i,j)!=GetOrder(i,d-j+1))
            {
                isSym=false;
                break;
            }
        }
        if (isSym && i%2==0)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}