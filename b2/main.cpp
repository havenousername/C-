#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct holiday{
  int student_id;
  string place;
};


bool isUnique(string place, vector<string> v){
  int i = 0;
  while (i < v.size() &&  v[i] != place)
  {
    i++;
  }
  return (i == v.size());
};

//subtask5
//use: print_groups(&students);
void print_groups(const vector<holiday> *data)
{
  const int data_size = data->size();
  unsigned short stud_to_check[data_size];
  vector<string> all_stud_travels;
  int groups = 0;

  memset(stud_to_check, 1, data_size);
  int first_stud = data->at(0).student_id;
  for (int i = 0; i < data_size; i++)
  {
    if (first_stud == data->at(i).student_id)
    {
      all_stud_travels.push_back(data->at(i).place);
    }
  }

  vector<string> all_curr_stud_travels;
  for (int curr = 1; curr < data_size; curr++)
  {
    if (!stud_to_check[curr])
      continue;
    int j = 1;
    for (; j < data_size; j++)
    {
      if (data->at(curr).student_id == data->at(j).student_id)
      {
        all_curr_stud_travels.push_back(data->at(j).place);
      }
    }
    if (all_stud_travels.size() == all_curr_stud_travels.size())
    {
      int all_matches = all_stud_travels.size();
      for (int i = 0; i < all_stud_travels.size(); i++)
      {
        if (find(all_stud_travels.begin(),
                 all_stud_travels.end(),
                 all_curr_stud_travels.at(i)) != all_stud_travels.end())
        {
          all_matches--;
          if (all_matches <= 0)
          {
            stud_to_check[j] = 0;
            groups++;
          }
        }
      }
    }
    all_curr_stud_travels.erase(all_curr_stud_travels.begin(), all_curr_stud_travels.end());
  }
  cout << "Possible groups found: " << groups << endl;
}

int main(){

  int N = 0, M = 0;

  cin >> N >> M;

  vector<holiday> students(M*2);
  for(int i = 0; i < M*2; i++){
    cin >> students[i].student_id;
    cin >> students[i].place;
  }

  // 1st solution
  cout << '#' << endl;
  vector<string> unique;
  for(int i = 0; i < M; i++){
    if(isUnique(students[i].place, unique)){
      unique.push_back(students[i].place);
    }
  }
  cout << unique.size() << endl;

  // 2nd solution
  cout << '#' << endl;
  vector<int> times(M+1);
  for(auto s : students){
    times[s.student_id]++;
  }

  for (int i = 1; i < M; i++)
  {
    if(times[i] != 0){
      cout << i << " " << times[i] << endl;
    }
  }
  // 3rd solution
  cout << '#' << endl;
  int maxCnt = -1;
  string most_place = "";
  for(int i = M; i >= 0; i--){
    int cnt = 0;
    string place = students[i].place;
    for(int j = i; j < M; j++){
      if(students[j].place == place){
        cnt++;
      }
    }
    if(cnt > maxCnt){
      most_place = place;
      maxCnt = cnt;
    }
  }
  cout << most_place << endl;
  cout << '#' << endl;

  // 4rth task
  int out = -1;
  for(int i = 1; i <= N; i++){
      for(auto s : students){
        if (s.student_id == i)
        {
          break;
        }else{
          out = i;
        }
      }   
  }
  cout << out << endl;
  cout << '#' << endl;

  // 5th task 
  vector<vector<string> > groups(M+1);
  for (int i = 0; i < M; i++)
  {
    groups[students[i].student_id].push_back(students[i].place);    
  }
  vector<string> str;
  vector<string>new_str;
  string old_str = "";
    
  for (int i = 1; i < M; i++)
  {
    sort(groups[i].begin(), groups[i].end());
    for (auto g : groups[i])
    {
      new_str.push_back(g);
    }
  }
  for(auto n : new_str){
    int j = 0;
    while (j < str.size() && str[j].compare(n) != 0)
    {
      j++;
    }
    if (j == str.size())
    {
      str.push_back(n);
    }
  }


  cout << str.size() << endl;
  print_groups(&students);

  return 0;
}