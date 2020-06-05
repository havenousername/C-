#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct banknote
{
  string country;
  string color;
  int value;
};


int main() {

  // number of banknotes
  int N = 0;
  cin >> N; 

  // struct array of banknotes
  vector<banknote> banknotes(N);
  for(auto b : banknotes){
    cin >> b.country >> b.color >> b.value;
  }  

  cout << '#' << endl;
  banknote smallest;
  smallest.value = INT_MAX;
  for (auto b : banknotes)
  {
    if(b.value < smallest.value){
      smallest.value = b.value;
      smallest.country = b.country;
      smallest.color = b.color;
    }
  }
  cout << '#' << endl;

  // second subtask 
  
  cout << '#' << endl;
  cout << '#' << endl;
  cout << '#' << endl;
  cout << '#' << endl;
  return 0;
}