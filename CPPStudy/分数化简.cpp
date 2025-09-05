//分数化简
#include <iostream>
using namespace std;

struct Fraction
{
    int son;
    int mom;
};

Fraction Cut(int a,int b) {
    for (int i = 2; i <= a; i++)
    {
        if (a%i==0 && b%i==0)
        {
            a=a/i;
            b=b/i;
            return Cut(a,b);
        }
    }
    Fraction frac={a,b};
    return frac;
}

int main() {
    int a,b;
    cin>>a>>b;
    Fraction frac;
    frac=Cut(a,b);
    cout<<frac.son<<" "<<frac.mom;
    return 0;
}