#include <iostream>
using namespace std;

bool equidistantTrio(int mid, int before, int after){
    if(mid - before == after - mid){
        return true;
    }
    return false;
};

int main() {
  int n = 0;
  cin >> n;
  int arr[n+1];
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
  }

  int indexTwo = 3;
  int indexOne = 2;
  int indexZero = 1;


  while(indexOne <= n && !equidistantTrio(arr[indexOne],arr[indexZero], arr[indexTwo])){
     indexOne++;
     indexZero++;
     indexTwo++;
  }
  if(indexOne <= n){
    cout << indexOne;
  }else{
    cout << 0;
  }
  
}
