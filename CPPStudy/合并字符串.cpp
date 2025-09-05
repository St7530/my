#include <iostream>
#include <string.h>
using namespace std;

char str1[100],str2[100];

void str_bin(char str1[], char str2[]) {
    strcat(str1,str2); // Append str2 to str1

    // Sort str1
    for (int i = 0; str1[i] != '\0'; i++)
    {
        for (int j = 1; str1[j] != '\0'; j++)
        {
            if (str1[j]<str1[j-1])
            {
                char tmp=str1[j];
                str1[j]=str1[j-1];
                str1[j-1]=tmp;
            }
        }
    }
}

int main()  
{
    cin>>str1>>str2;
    str_bin(str1,str2);
    cout<<str1;
    return 0;
} 