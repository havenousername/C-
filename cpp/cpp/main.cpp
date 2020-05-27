#include <iostream>
using namespace std;

int main() {
  int n = 0;
  
  cin >> n;
  string words[n];
  
  for(int i = 0; i < n; i++){
    cin >> words[i];
  }
  
  string code = "";
  for(int i = 0; i < n; i++){
    bool number = true;
      int temp = i;
    for(int j = 0; j < words[temp].length() - 1; j++){
      if((words[temp][j] < '0') || (words[i][j] > '9')){
        number = false;
      }
    }
    if(number && words[i].length() > code.length()){
        code = words[i];
    }
    
  }
  
  cout << code << endl;
  
}
