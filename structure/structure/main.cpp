#include <iostream>
#include <vector>
using namespace std;

struct person {
  string name;
  int crimes;
};

int main() {
  // Write your program here.
  int n;
  cin >> n;
  person p[n];
  for (int i = 0; i < n; i++) {
      cin >> p[i].name >> p[i].crimes;
  }
  
  vector<person> list;
  for (int i = 0; i < n; i++) {
      if (p[i].crimes >= 3) {
          list.push_back(p[i]);
      }
  }
  
  cout << list.size() << endl;
  for (int i = 0; i < list.size(); i++) {
      cout << list[i].name << endl;
  }
}
