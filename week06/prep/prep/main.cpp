#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
  int n = 0, m = 0;
  cin >> n >> m;
  int arr[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }
  vector<int> mi;
  for(int i = 0; i < n; i++){
      int min = INT_MAX;
      
      for (int j = 0; j < m; j++) {
          if (arr[i][j] <min) {
              min = arr[i][j];
          }
      }
      mi.push_back(min);
  }
    int max = INT_MIN;
    for (auto m : mi) {
        if (max < m) {
            max = m;
        }
    }
    cout << max;
}

