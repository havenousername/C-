#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct multi_arr {
  int index;
  vector<int> values;
};

bool compare_multi(multi_arr a1, multi_arr a2){
  return a1.index < a2.index;
};

bool hasNoDuplicates(vector<int> v, int i){
  int j = 0;
  while (j < v.size() && i != v[j])
  {
    j++;
  }
  return (j == v.size());
}

bool hasZeros(vector<int> values){
  int j = 0;
  while(j < values.size() && values[j] != 0){
    j++;
  }
  return (j < values.size());
};

vector<multi_arr> push(vector<multi_arr> s, int index, int value){
  int j = 0;
  while (j < s.size() && s[j].index != index)
  {
    j++;
  }
  if(j < s.size()){
    s[j].values.push_back(value);
  }else{
    multi_arr n;
    n.index = index;
    n.values.push_back(value);
    s.push_back(n);
  }
  return s;
};

int main(){
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
  vector<vector<int> > transpose(M);

  for (int j = 0; j < M; j++)
  {
    for (int i = 0; i < N; i++)
    {
      transpose[j].push_back(weather[i][j]);
    }
  }

  vector<multi_arr> out;

  // checking transposion
  cout << "Tansposed matrix: \n";
  for(auto o : transpose){
    for(auto v : o){
      cout << v << " ";
    }
    cout << endl;
  }
  cout << "End of transposed\n";

  for (int i = 0; i < transpose.size(); i++)
  {
    int max = 0;
    int index = 0;
    for (int j = 0; j < transpose[i].size(); j++)
    {
      if (transpose[i][j] > L && transpose[i][j] > max && hasNoDuplicates(transpose[i], transpose[i][j]))
      {
        index = j;
        max = transpose[i][j];
      }
    }
    out = push(out, index+1, max);
  }

  sort(out.begin(), out.end(), compare_multi);

  int biggest = 0;
  int cnt = 0;

  for (int i = 0; i < out.size() ; i++)
  {
    if(out[i].values.size() > cnt && !hasZeros(out[i].values)){
      biggest = out[i].index;
      cnt = out[i].values.size();
    }
  }

  for(auto o : out){
    cout << "City: " << o.index << " Temperatures: ";
    for(auto v : o.values){
      cout << v << " ";
    }
    cout << endl;
  }
  cout << biggest << endl;
  cout << endl;
}