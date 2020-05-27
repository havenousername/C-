//
//  main.cpp
//  week05
//
//  Created by Andrei Cristea on 2020. 05. 01..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>

#define M 3
#define N 9

void stormy_days(){
    int cnt = 0, n, k;
    std::cin >> n >> k;
    int days[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> days[i];
    }
    for (int i = 0; i < n; i++) {
        if (days[i] >100) {
            cnt++;
        }
    }
    std::cout << cnt;
}

std::string encript(std::string str){
    std::string encripted = "";
    char arr[M][N] = {
        {'i', 'o', 'q', 'h', 'b', 'f', 'y', 'l', 'w'},
        {'n', 'r', 'a', 'g', 's', 'k', 't', 'e', 'z'},
        {'d', 'u', 'p', 'x', 'c', 'j', 'v', 'm', ' '},
    };
    int k = 0;
    
    for (; k < str.size(); k++) {
        for (int i = 0; i < M; i++) {
              for (int j = 0; j < N; j++) {
                  if (arr[i][j] == str[k]) {
                      encripted.push_back((char)i+97);
                      encripted.push_back((char)j+97);
                      break;
                  }
              }
          }
    }
    return encripted;
};

int main(int argc, const char * argv[]) {
//    std::string str;
//    std::cin >> str;
//    std::cout << encript(str);
    int n = 0;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int i = 0;
    while (i < n && arr[i] > 0) {
        i++;
    }
    if (i < n) {
        std::cout << i+1;
    }else{
        std::cout << -1;
    }
    
    stormy_days();
    return 0;
}
