#include <iostream>
#include <string>
using namespace std;

string invert(string s) {
    string sum;
    for (int i = 1; i <= s.size(); i++)
    {
        sum+=s[s.size()-i];
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    string str[n];
    for (int i = 0; i < n; i++)
    {
        cin>>str[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<invert(str[i])<<endl;
    }
    return 0;
}