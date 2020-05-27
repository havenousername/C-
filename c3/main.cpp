#include <iostream>
#include <vector>
using namespace std;

struct count_index
{
  int count;
  int max;
  int index;
};

struct biggest_return
{
  int count;
  int index;
};

typedef struct count_index count_index;
typedef struct biggest_return biggest_return;

biggest_return take_biggest(int j, int limit, int inc, int size, int max, int *arr)
{
  biggest_return out = {*(arr + j), 1};
  int index = 1;

  for (int i = j; i < (size - limit); i += inc)
  {
    if (out.count < *(arr + i) && *(arr + i) > max)
    {
      out.count = *(arr + i);
      out.index = index;
    }
    index++;
  }
  return out;
};

count_index make_count_index(int count, int temp, int index)
{
  count_index my_count_index = {count, temp, index};
  return my_count_index;
};

bool exists_in_struct(vector<count_index> warmest_weather, int index)
{
  int i = 0;
  while (i < warmest_weather.size() && warmest_weather[i].max != index)
  {
    i++;
  };

  return (i < warmest_weather.size());
};

bool is_unique(int number, vector<count_index> v)
{
  int i = 0;
  while (i < v.size() && v[i].count != number)
  {
    i++;
  }
  return (i == v.size());
}

//int take_smallest_index(vector<count_index> v){
//    vector<count_index> identical;
//    int count = v[0].count;
//    for (int i = 0; i < v.size(); i++) {
//        if (v[i].count == count) {
//            identical.push_back(v[i]);
//        }else if(v[i].count > count){
//            count =
//        }
//    }
//    int min = v[0].index;
//    int min_value = v[0].max;
//}

int unique_index(vector<count_index> v)
{
  int max = v[0].count;
  int index = v[0].index;
  vector<count_index> ind_arr;
  for (int a = 1; a < v.size(); a++)
  {
    if (max < v[a].count)
    {
      index = v[a].index;
    }
    else if (max == v[a].count)
    {
      ind_arr.push_back(v[a]);
    }
  }
  return index;
};

int find_temp(vector<count_index> warmest_weather, int index)
{
  int i = 0;
  while (i < warmest_weather.size() && warmest_weather[i].max != index)
  {
    i++;
  };

  return i;
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
  vector<count_index> warmest_weather;
  int count = 0;
  for (int j = 0; j < M; j++)
  {
    biggest_return temp = take_biggest(j, (N - j), M, N * M, L, &weather[0][0]);
    int max = temp.count;
    int index = temp.index;
    if (!exists_in_struct(warmest_weather, max))
    {
      count = 0;
      count++;
      warmest_weather.push_back(make_count_index(count, max, index));
    }
    else
    {
      count++;
      warmest_weather[find_temp(warmest_weather, max)] = make_count_index(count, max, index);
    }
  }
  int index = unique_index(warmest_weather);

  cout << index << endl;
  return 0;
}
