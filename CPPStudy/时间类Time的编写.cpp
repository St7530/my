#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    friend istream& operator>>(istream&,Time&); // Input
    friend ostream& operator<<(ostream&,Time&); // Output
    Time& operator+=(const Time&); // Add
    Time& operator-=(const Time&); // Subtract
    Time& operator++(); // Pre increment
    Time& operator--(); // Pre decrement
    Time operator++(int); // Post increment
    Time operator--(int); // Post decrement
    friend void FormatTime(Time&); // Format
};

void FormatTime(Time& t)
{
    while(t.second<0)
    {
        t.minute--;
        t.second+=60;
    }
    while(t.second>=60)
    {
        t.minute++;
        t.second-=60;
    }
    while(t.minute<0)
    {
        t.hour--;
        t.minute+=60;
    }
    while(t.minute>=60)
    {
        t.hour++;
        t.minute-=60;
    }
    while(t.hour<0)
    {
        t.hour+=24;
    }
    while(t.hour>=24)
    {
        t.hour-=24;
    }
}

istream& operator>>(istream& input,Time& t){
    input>>t.hour>>t.minute>>t.second;
    return input;
}

ostream& operator<<(ostream& output,Time& t){
    FormatTime(t);
    output<<setw(2)<<setfill('0')<<t.hour<<":"<<setw(2)<<setfill('0')<<t.minute<<":"<<setw(2)<<setfill('0')<<t.second<<endl;
    return output;
}

Time& Time::operator+=(const Time& t){
    this->hour+=t.hour;
    this->minute+=t.minute;
    this->second+=t.second;
    return *this;
}

Time& Time::operator-=(const Time& t){
    this->hour-=t.hour;
    this->minute-=t.minute;
    this->second-=t.second;
    return *this;
}

Time& Time::operator++(){
    ++this->second;
    return *this;
}

Time& Time::operator--(){
    --this->second;
    return *this;
}

Time Time::operator++(int){
    Time tmp=*this;
    this->second++;
    return tmp;
}

Time Time::operator--(int){
    Time tmp=*this;
    this->second--;
    return tmp;
}

// The `main` function is given.
int main()
{
    Time t1,t2;
    cin>>t1;
    cin>>t2;
    cout<<(t1+=(t2++));
    cout<<(t1-=t2);
    cout<<++t2;
    cout<<(t2+=(t1--));
    cout<<--t1;
    cout<<(t2-=t1);

    return 0;
}




