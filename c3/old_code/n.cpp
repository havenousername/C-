#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct multi_arr
{
  int index;
  vector<int> values;
};

bool compare_multi(multi_arr a1, multi_arr a2)
{
  return a1.index < a2.index;
};

bool hasNoDuplicates(vector<int> v, int limit, int i)
{
  int j = 0;
  while ((j < v.size() && i != v[j]) || j == limit)
  {
    j++;
  }
  return (j == v.size());
}

bool hasAllZeros(vector<int> values, int value = 0)
{
  int j = 0;
  while (j < values.size() && values[j] == value)
  {
    j++;
  }
  return (j == values.size());
};

bool allLessThenL(vector<vector<int>> values, int value = 0)
{
  int j = 0;
  for (auto v : values)
  {
    int i = 0;
    while (i < v.size() && v[i] <= value)
    {
      i++;
    }
    j += i;
  }
  return (j == values.size() * values[0].size());
};

vector<multi_arr> push(vector<multi_arr> s, int index, int value)
{
  int j = 0;
  while (j < s.size() && s[j].index != index)
  {
    j++;
  }
  if (j < s.size())
  {
    s[j].values.push_back(value);
  }
  else
  {
    multi_arr n;
    n.index = index;
    n.values.push_back(value);
    s.push_back(n);
  }
  return s;
};

int give_biggest(vector<multi_arr> out)
{
  int biggest = 0;
  int cnt = 0;

  for (int i = 0; i < out.size(); i++)
  {
    if (out[i].values.size() > cnt)
    {
      biggest = out[i].index;
      cnt = out[i].values.size();
    }
  }
  return biggest;
};

int main()
{
  int N = 0, M = 0, L = 0;
  cin >> N >> M >> L;
  int weather[N][M];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> weather[i][j];
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

  vector<multi_arr> out;

  // checking transposion
  // cout << "Transposed matrix: \n";
  // for (auto o : transpose)
  // {
  //   for (auto v : o)
  //   {
  //     cout << v << " ";
  //   }
  //   cout << endl;
  // }
  // cout << "End of transposed\n";

  for (int i = 0; i < transpose.size(); i++)
  {
    int max = 0;
    int index = 0;
    for (int j = 0; j < transpose[i].size(); j++)
    {
      if (transpose[i][j] > max && hasNoDuplicates(transpose[i], j, transpose[i][j]))
      {
        index = j;
        max = transpose[i][j];
      }
      else if (!hasNoDuplicates(transpose[i], j, transpose[i][j]) && give_biggest(out) == j && transpose[i][j] > max)
      {
        index = j;
        max = transpose[i][j];
      }
    }
    cout << endl;
    out = push(out, index + 1, max);
  }

  sort(out.begin(), out.end(), compare_multi);
  int biggest = give_biggest(out);

  // Second debugging
  for (auto o : out)
  {
    cout << "City: " << o.index << " Temperatures: ";
    for (auto v : o.values)
    {
      cout << v << " ";
    }
    cout << endl;
  }
  cout << biggest;
}
