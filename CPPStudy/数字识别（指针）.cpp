#include <iostream>

using namespace std;

int main()
{
    int sum=0;
    bool isLastInt=false;
    string str,all;
    string *pStr=&str,*pAll=&all;
    getline(cin,*pStr);
    for (unsigned int i = 0; i < (*pStr).length(); i++)
    {
        if ((*pStr)[i]>='0' && (*pStr)[i]<='9')
        {
            if (isLastInt==false)
            {
                sum++;
            }
            *pAll+=(*pStr)[i];
            isLastInt = true;
        }
        else
        {
            if (isLastInt == true)
            {
                *pAll+=' ';
            }
            isLastInt = false;
        }
    }
    cout<<"There are "<<sum<<" integers:"<<*pAll;
    return 0;
}

