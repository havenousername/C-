
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin>>n;
  string words[n];
  string special[n];
    int cnt = 0;
  for (int i=0; i<n; i++)
  {
    cin>>words[i];
  }
  for (int i=0; i<n-1; i++)
  {
    for (int j=i+1; j<n; j++)
    {
      if (words[i][j]<words[i][j+1])
      {
        special[cnt]=words[i];
        cnt++;
      }
    }
  }
  cout<<cnt<<endl;
  for (int i=0; i<cnt; i++)
  {
    cout<<special[i]<<endl;
  }
}
