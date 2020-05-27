#include <iostream>
#include <vector>
using namespace std;

struct count_index {
  int count;
  int max;
  int index;
};

struct biggest_return {
    int count;
    int index;
};

typedef struct count_index count_index;
typedef struct biggest_return biggest_return;

biggest_return take_biggest(int limit,int size, int max,int *arr){
    int biggest = *(arr);
    int j = 0;
    biggest_return out = {*(arr), 1};
    while (j < (limit + size)) {
        if (*(arr+j) > max && *(arr+j) > biggest)
        {
          biggest = *(arr+j);
          out.count = biggest;
          out.index = j+1;
        }
        j++;
    }
    return out;
};

void transpose(int* p, int m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = *(p + i * m + j);
            *(p + i * m + j) = *(p + j * m + i);
            *(p + j * m + i) = temp;
        }
    }
}

count_index make_count_index(int count,int temp, int index){
    count_index my_count_index = {count,temp, index};
    return my_count_index;
};

bool exists_in_struct(vector <count_index> warmest_weather,int index){
    int i = 0;
    while (i < warmest_weather.size() && warmest_weather[i].max != index){
        i++;
    };

    return (i < warmest_weather.size());
};

bool is_unique(int number, vector<count_index> v){
    int  i = 0;
    while (i < v.size() && v[i].count != number) {
        i++;
    }
    return (i == v.size());
}

int unique_index(vector<count_index> v){
    int max = v[0].count;
    int index = v[0].index;
    for(auto a : v){
        if (max < a.count && is_unique(a.count, v)) {
            index = a.index;
        }
    }
    return index;
};

int find_temp(vector <count_index> warmest_weather,int index){
    int i = 0;
    while (i < warmest_weather.size() && warmest_weather[i].max != index){
        i++;
    };

    return i;
};


int main(){
  int N = 0, M = 0, L = 0;
  cin >> N >> M >> L;
  int weather[N][M];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
        cin >> weather[i][j];
    }
  }
  vector<count_index> warmest_weather;
  int count = 0;
  for (int j = 0; j < M; j++)
  {
    transpose(&weather[0][0], M, N);
    biggest_return temp = take_biggest(j*M,N,L, &weather[0][0]);
    int max = temp.count;
    int index = temp.index;
    if (!exists_in_struct(warmest_weather, max))
    {
        count = 0;
        count++;
        warmest_weather.push_back(make_count_index(count,max,index));
    }else{
        count++;
        warmest_weather[find_temp(warmest_weather, max)] = make_count_index(count,max,index);
    }
    
  }
  int index = unique_index(warmest_weather);

  cout << index << endl;
  return 0;
}
