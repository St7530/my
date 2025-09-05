#include <iostream>
using namespace std;

int main() {
    int n1,n2;

    // Input
    cin>>n1;
    int a[n1];
    for (int i = 0; i < n1; i++)
    {
        cin>>a[i];
    }
    cin>>n2;
    int b[n2];
    for (int i = 0; i < n2; i++)
    {
        cin>>b[i];
    }
    
    bool doesHave=false;
    int mergeCount=0;
    // Count merge
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i]==b[j])
            {
                doesHave=true;
                break;
            }
            doesHave=false;
        }
        if (doesHave==false)
        {
            mergeCount++;
        }
        
    }

    int sumCount=n2+mergeCount;
    int c[sumCount];
    // Copy b[] to c[]
    for (int i = 0; i < n2; i++)
    {
        c[i]=b[i];
    }
    
    doesHave=false;
    mergeCount=0;
    // Merge a[] to c[]
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i]==b[j])
            {
                doesHave=true;
                break;
            }
            doesHave=false;
        }
        if (doesHave==false)
        {
            c[n2+mergeCount]=a[i];
            mergeCount++;
        }
    }
    
    // Sort c[] from largest to smallest
    for (int i = sumCount; i >= 0; i--)
    {
        for (int j = 0; j < sumCount-1; j++)
        {
            if (c[j]<c[j+1])
            {
                int tmp=c[j];
                c[j]=c[j+1];
                c[j+1]=tmp;
            }
        }
    }
    
    // Print c[]
    for (int i = 0; i < sumCount; i++)
    {
        cout<<c[i];
        if (i<sumCount-1)
        {
            cout<<" ";
        }
    }

    return 0;
}