#include <iostream>
using namespace std;
int main()
{
  int N, M, T;
  cin >> N >> M >> T;
  int Sment[N][M];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> Sment[i][j];
    }
  }
  int mosts[M];
  for (int j = 0; j < M; j++)
  {
    int max = -999999;
    for (int i = 0; i < N; i++)
    {
      if (Sment[i][j] > max && Sment[i][j] > T)
      {
        max = Sment[i][j];
      }
    }
    mosts[j] = max;
  }
  int max = -9999999;
  int index;
  for (int i = 0; i < N; i++)
  {
    int cnt = 0;
    for (int j = 0; j < M; j++)
    {
      if (Sment[i][j] == mosts[j])
        cnt++;
    }
    if (cnt > max)
    {
      max = cnt;
      index = i + 1;
    }
  }
  cout << index << endl;
  return 0;
}