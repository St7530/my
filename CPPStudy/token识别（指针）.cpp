#include <iostream>
#include <string>
using namespace std;

int main()
{
    int intSum=0,wordSum=0,symbolSum=0;
    int lastType=0; // 1 for int; 2 for word; 3 for symbol
    string str,intAll,wordAll,symbolAll;
    string *pStr=&str,*pIntAll=&intAll,*pWordAll=&wordAll,*pSymbolAll=&symbolAll;
    getline(cin,*pStr);
    for (unsigned int i = 0; i < (*pStr).length(); i++)
    {
        if ((*pStr)[i]>='0' && (*pStr)[i]<='9') // Now is int
        {
            if (lastType==0)
            {
                intSum++;
            }
            switch (lastType){
            case 1:
                break;
            case 2:
                intSum++;
                *pWordAll+=' ';
                break;
            case 3:
                intSum++;
                *pSymbolAll+=' ';
                break;
            }
            *pIntAll+=(*pStr)[i];
            lastType=1;
            continue;
        }
        else if ((*pStr)[i]>='a' && (*pStr)[i]<='z') // Now is word
        {
            if (lastType==0)
            {
                wordSum++;
            }
            switch (lastType){
            case 1:
                wordSum++;
                *pIntAll+=' ';
                break;
            case 2:
                break;
            case 3:
                wordSum++;
                *pSymbolAll+=' ';
                break;
            }
            *pWordAll+=(*pStr)[i];
            lastType=2;
            continue;
        }
        else if (((*pStr)[i]>='!' && (*pStr)[i]<='/') || ((*pStr)[i]>=':' && (*pStr)[i]<='@') || ((*pStr)[i]>='{' && (*pStr)[i]<='~')) // Now is symbol
        {
            if (lastType==0)
            {
                symbolSum++;
            }
            switch (lastType){
            case 1:
                symbolSum++;
                *pIntAll+=' ';
                break;
            case 2:
                symbolSum++;
                *pWordAll+=' ';
                break;
            case 3:
                symbolSum++;
                *pSymbolAll+=' ';
                break;
            }
            *pSymbolAll+=(*pStr)[i];
            lastType=3;
            continue;
        }
        // Now is space
        switch (lastType)
        {
        case 1:
            *pIntAll+=' ';
            break;
        case 2:
            *pWordAll+=' ';
            break;
        case 3:
            *pSymbolAll+=' ';
            break;
        }
        lastType=0;
    }

    cout<<"There are "<<intSum<<" integers:"<<*pIntAll<<endl;
    cout<<"There are "<<wordSum<<" words:"<<*pWordAll<<endl;
    cout<<"There are "<<symbolSum<<" symbles:"<<*pSymbolAll<<endl; // Maybe `symble` is a misspelling
    return 0;
}