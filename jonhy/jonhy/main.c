//
//  main.c
//  jonhy
//
//  Created by Andrei Cristea on 2020. 04. 03..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n = 0;
  cin >> n;
  vector<int> numberOfSlaves(n);
  vector<int> index;
  for(int i =1;i <= numberOfSlaves.size(); i++){
    cin >> numberOfSlaves[i];
    if(numberOfSlaves[i] >= 1000){
      index.push_back(i);
    }
  }
  for(auto i : index){
    cout << index[i];
  }
}
