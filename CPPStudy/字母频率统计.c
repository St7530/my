#include <stdio.h>
#include <string.h>

char ToLower(char c) {
    if (c>='A' && c<='Z')
        return c-32;
    else
        return c;
}

int main() {
    char str[100]={'\0'};
    char tmp[100];
    while (fgets(tmp, sizeof(tmp), stdin) != NULL) {
        strcat(str, tmp);
    }
    int a[26]={0};

    // Count
    for (int i = 0; i < strlen(str); i++)
    {
        if (ToLower(str[i])>='a' || ToLower(str[i])<='z')
        {
            a[ToLower(str[i])-'a']++;
        }
        
    }
    
    // Get max count
    int max=0;
    for (int i = 0; i < 26; i++)
    {
        if (a[i]>max)
            max=a[i];
    }
    
    // Print
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (a[j]>=max-i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("abcdefghijklmnopqrstuvwxyz");
    return 0;
}