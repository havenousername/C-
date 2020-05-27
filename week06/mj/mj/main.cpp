#include <iostream>
using namespace std;
int main() {
int n, h;
cin>>n>>h;
int mood[n][h];
for (int i=0; i<n; i++)
{
    for (int j=0; j<h; j++)
    {
        cin>>mood[i][j];
    }
}
int output=0;
for (int j=0; j<h;j++)
    {
        int  i = 0;
        for (;i<n;)
        {
            if (mood[i][j]==1)
            {
                i++;
            }else{
                break;
            }
        }
        if (i == n)
        {
            output=j;
            break;
        }
}

cout<<output+1;

return 0;
}
