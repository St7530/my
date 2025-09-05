#include <iostream>
#include <string>
using namespace std;

int Count(string str) {
    int count=1;
    for (unsigned i = 0; i < str.length(); i++)
        {
            if (str[i]==' ')
            {
                count++;
            }
        }
    return count;
}

void InitArray(int a[],string str) {
    int j=0;
    string t="";
    for (unsigned i = 0; i < str.length(); i++)
    {
        if (str[i]==' ')
        {
            a[j]=stoi(t);
            j++;
            t="";
        }
        else
        {
            t+=str[i];
            if (i==str.length()-1)
            {
                a[j]=stoi(t);
            }
        }
    }
    
}

int main() {
    string str;
    getline(cin,str);   int ac=Count(str);  int a[ac];  InitArray(a,str);   // Create a[]
    getline(cin,str);   int bc=Count(str);  int b[bc];  InitArray(b,str);   // Create b[]

    bool doesHave=false;
    int mergeCount_a=0,mergeCount_b=0;
    // Count merge - a[]
    for (int i = 0; i < ac; i++)
    {
        doesHave=false;
        for (int j = 0; j < bc; j++)
        {
            if (a[i]==b[j])
            {
                doesHave=true;
                break;
            } 
        }
        if (doesHave==false)
            mergeCount_a++;
    }
    // Count merge - b[]
    for (int i = 0; i < bc; i++)
    {
        doesHave=false;
        for (int j = 0; j < ac; j++)
        {
            if (b[i]==a[j])
            {
                doesHave=true;
                break;
            } 
        }
        if (doesHave==false)
            mergeCount_b++;
    }
    
    int count=mergeCount_a+mergeCount_b;
    int c[count];
    int ci=0;
    // Merge a[] to c[]
    for (int i = 0; i < ac; i++)
    {
        doesHave=false;
        for (int j = 0; j < bc; j++)
        {
            if (a[i]==b[j])
            {
                doesHave=true;
                break;
            } 
        }
        if (doesHave==false)
        {
            c[ci]=a[i];
            ci++;
        }
    }
    // Merge b[] to c[]
    for (int i = 0; i < bc; i++)
    {
        doesHave=false;
        for (int j = 0; j < ac; j++)
        {
            if (b[i]==a[j])
            {
                doesHave=true;
                break;
            } 
        }
        if (doesHave==false)
        {
            c[ci]=b[i];
            ci++;
        }
    }
    
    // Sort c[] from largest to smallest
    for (int i = count; i >= 0; i--)
    {
        for (int j = 0; j < count-1; j++)
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
    for (int i = 0; i < count; i++)
    {
        cout<<c[i];
        if (i<count-1)
            cout<<" ";
    }
    
    return 0;
}