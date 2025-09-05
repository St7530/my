#include <iostream>
using namespace std;

int main() {
    int a[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>a[i][j];
        }
    }
    
    bool isLargestInRow=true;
    bool isSmallestInCol=true;
    int row,col;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            isLargestInRow=true;
            isSmallestInCol=true;
            // Is largest in the row?
            for (int i = 0; i < 3; i++)
            {
                if (a[r][c]<a[r][i])
                {
                    isLargestInRow=false;
                    break;
                }
            }
            
            // Is Smallest in the column?
            for (int i = 0; i < 3; i++)
            {
                if (a[r][c]>a[i][c])
                {
                    isSmallestInCol=false;
                    break;
                }
            }

            if (isLargestInRow && isSmallestInCol)
            {
                row=r;
                col=c;
                break;
            }
        }
        if (isLargestInRow && isSmallestInCol)
            break;
    }

    if (isLargestInRow && isSmallestInCol)
        cout<<"Saddle point:a["<<row<<"]["<<col<<"]="<<a[row][col];
    else
        cout<<"There is no saddle point";
    
    return 0;
}