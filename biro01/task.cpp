#include <iostream>
#include <vector>

using namespace std;

struct chain{
  string animal;
  string victim;
};

typedef struct chain chain;

bool isAnimal(const string& victim, const vector<chain>& v){
  int i = 0;
  while(i < v.size() && victim != v[i].animal){
    i++;
  }
  return ( i < v.size());
};

bool isUnique(const string& u, const vector<string>& v){
  int i = 0;
  while(i < v.size() && u != v[i]){
    i++;
  }
  return ( i == v.size()); 
}

vector<string> make_set(vector<string>& arr){
  vector<string> set;
  for(int i = 0; i < arr.size(); i++){
    if(isUnique(arr[i], set)){
      set.push_back(arr[i]);
    }  
  }
  return set;
} 

int main() {
  int N = 0;
  cin >> N;
  vector<chain> animals(N);
  for(int i = 0; i < animals.size(); i++){
    cin >> animals[i].animal >> animals[i].victim;
  }
  vector<string> carnivores;
  for(int i = 0; i < animals.size(); i++){
    if(isAnimal(animals[i].victim, animals)){
      carnivores.push_back(animals[i].animal);
    }
  }
  vector<string> set = make_set(carnivores);
  cout << set.size() << endl;
  for(auto c : set){
    cout << c << endl;
  }
  return 0;
}