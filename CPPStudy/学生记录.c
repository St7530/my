#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Student{
    int id;
    char name[6];
    int age;
};

void Print(struct Student stu) {
    printf("%3d%6s%3d\n",stu.id,stu.name,stu.age);
}

bool IsBigger(char str1[],char str2[]) {
    int count=(strlen(str1)<strlen(str2))?strlen(str1):strlen(str2); // Get the smaller length
    for (int i = 0; i < count; i++)
    {
        if (str1[i]==str2[i])
        {
            continue;
        }
        else if (str1[i]>str2[i])
        {
            return true;
        }
        else
            return false;
    }
    return false; // Useless, just to escape the warning.
}

int main(){
    int n;
    scanf("%d",&n);
    struct Student stu[50];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&stu[i].id);
        scanf("%s",stu[i].name); // No need to use `&`
        scanf("%d",&stu[i].age);
    }

    // Sort by name
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (IsBigger(stu[j].name,stu[j+1].name))
            {
                struct Student tmp=stu[j+1];
                stu[j+1]=stu[j];
                stu[j]=tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        Print(stu[i]);
    
    // Sort by age
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i-1; j++)
        {
            if (stu[j].age>stu[j+1].age)
            {
                struct Student tmp=stu[j+1];
                stu[j+1]=stu[j];
                stu[j]=tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        Print(stu[i]);

    return 0;
}