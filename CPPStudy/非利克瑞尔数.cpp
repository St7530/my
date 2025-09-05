/*
【问题描述】
利克瑞尔数（Lychrel Number）指的是将该数各数位逆序翻转后形成的新数相加，并将该过程反复迭代后，结果永远无法是一个回文数的自然数。57就是一个非利克瑞尔数：57+75=132, 132+231=363，363是一个回文数。请编写程序，输入一个自然数（非利克瑞尔数），请计算其最终的回文数是多少及每次迭代过程。
注意：假设输入的整数和中间产生的整数都不超过int数据类型的表示范围。
【输入形式】
从标准输入读入一个正整数。
【输出形式】
在标准输出上输出迭代过程和最终的回文数。分行输出每次迭代过程：先输出迭代次数（从1开始计数），后跟英文冒号:，然后是两数相加等于某数的等式，其中的符号都是英文符号，没有空格。在最后一行输出最终得到的回文数。
若输入的整数本身就是回文数，则不输出任何迭代过程，直接输出该回文数。
【样例1输入】
109
【样例1输出】
1:109+901=1010
2:1010+101=1111
1111
【样例1说明】
输入的非利克瑞尔数为109，经过两次迭代可得到回文数：第一次迭代为109和其逆序数901相加得1010，第二次迭代为上次迭代得到的1010加上其逆序数101（注意：高位的0省略）得1111，1111就是最终得到的回文数。
【样例2输入】
909
【样例2输出】
909
【样例2说明】
输入的非利克瑞尔数为909，其本身为回文数，直接输出，没有迭代过程。
*/

#include <iostream>
#include <cmath>
using namespace std;
int Digit(int a)
{
    int d;
    for(int i=1;;i++)
    {
        if(a<pow(10,i))
        {
            d=i;
            return d;
        }
    }
}

int Reverse(int a)
{
    int d=Digit(a);
    int s=0;
    for(int i=1;i<=d;i++)
    {
        s+=(a/(int)pow(10,i-1)%10)*(int)pow(10,d-i);
    }
    return s;
}

int Order(int a,int o)
{
    int b=a/(int)pow(10,o-1)%10;
    return b;
}

bool isSymmetry(int a)
{
    bool isSym=true;
    for(int i=1;i<=Digit(a)/2;i++)
    {
        if(Order(a,i)!=Order(a,Digit(a)-i+1))
        {
            isSym=false;
            break;
        }
    }
    return isSym;
}

int main()
{
    int a;
    cin>>a;
    int result=a;
    for(int i=1;isSymmetry(result)==false;i++)
    {
        cout<<i<<":"<<result<<"+"<<Reverse(result)<<"=";
        result=result+Reverse(result);
        cout<<result<<endl;
    }
    cout<<result;
    return 0;
}

