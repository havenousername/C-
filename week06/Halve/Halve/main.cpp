//
//  main.cpp
//  Halve
//
//  Created by Andrei Cristea on 2020. 05. 14..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int M = 0, N = 0;
    cin >> N >> M;
    char v[N][M];
    for(int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++) {
            cin >> v[i][j];
        }
    }
    char halved[N/2][M/2];
    for (int i = 1; i <= N/2; i++) {
        for (int j = 1; j <= M/2; j++) {
            halved[i][j] = (v[2*i][2*j] + v[2*i-1][2*j] + v[2*i][2*j-1] + v[2*i-1][2*j-1])/4;
        }
    }
    for (int i = 1; i <= N/2; i++) {
        for (int j = 1; j <= M/2; j++) {
            cout << halved[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
