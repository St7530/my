#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[9][9]={-1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin>>a[i][j];
    
    // Calculate
    bool isRemoved[9][9]={false};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((a[i][j]==a[i][j+1])&&(a[i][j]==a[i][j-1]))
            {
                isRemoved[i][j]=true;
                isRemoved[i][j+1]=true;
                isRemoved[i][j-1]=true;
            }
            if ((a[i][j]==a[i+1][j])&&(a[i][j]==a[i-1][j]))
            {
                isRemoved[i][j]=true;
                isRemoved[i+1][j]=true;
                isRemoved[i-1][j]=true;
            }
        }
    }

    // Print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<(isRemoved[i][j]?0:a[i][j]);
            if (j<m-1)
                cout<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}