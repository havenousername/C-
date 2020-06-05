#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
  ifstream fin;
  fin.open("input2.txt");
  int N = 0, M = 0, Limit = 0;
  fin >> N >> M >> Limit;
  vector<vector<int>> weather(N, vector<int>(M));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      fin >> weather[i][j];
    }
  }
  vector<vector<int>> transpose(M);
  for (int j = 0; j < M; j++)
  {
    for (int i = 0; i < N; i++)
    {
      transpose[j].push_back(weather[i][j]);
    }
  }
  vector<vector<int>> ans(N);

  for (int i = 0; i < transpose.size(); i++)
  {
    int max = 0;
    int index = 0;
    for (int j = 0; j < transpose[i].size(); j++)
    {
      if (transpose[i][j] > max)
      {
        max = transpose[i][j];
        index = j;
      }
    }
    if (max >= Limit)
    {
      ans[index].push_back(max);
    }
  }
  int max_days = 0;
  for (int i = 0; i < N; i++)
  {
    if (ans[i].size() > max_days)
    {
      max_days = ans[i].size();
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (ans[i].size() == max_days)
    {
      cout << i + 1;
      break;
    }
  }
}