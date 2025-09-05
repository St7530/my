#include <iostream>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

bool isLeap(int year) {
    if (year%100==0)
    {
        if (year%400==0)
            return true;
    } 
    else if (year%4==0)
        return true;
    return false;
}

int ParseDate(Date date) { // Convert Date to int
    int sum=0;
    Date stdDate={1970,1,1}; // The zero day, you'd better not change it

    for (int y = stdDate.year; y < date.year; y++)
        sum+=isLeap(y)?366:365;
    
    for (int m = stdDate.month; m < date.month; m++)
    {
        if (m==2)
        {
            sum+=isLeap(date.year)?29:28;
        }
        else if ((m<=7 && m%2!=0) || (m>=8 && m%2==0))
        {
            sum+=31;
        }
        else if ((m<=6 && m%2==0) || (m>=9 && m%2!=0))
        {
            sum+=30;
        }
    }

    sum+=date.day-stdDate.day;
    
    return sum;
}

int main() {
    Date date1,date2;
    cin>>date1.year>>date1.month>>date1.day;
    cin>>date2.year>>date2.month>>date2.day;
    cout<<ParseDate(date2)-ParseDate(date1);
    return 0;
}