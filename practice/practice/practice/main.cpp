//
//  main.cpp
//  practice
//
//  Created by Andrei Cristea on 2020. 05. 09..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct company {
    int id, gen, count;
};

int main(int argc, const char * argv[]) {
    int N = 0, M = 0;
    cin >> N;
    vector<string> companies(N);
    for (int i = 0; i < N; i++) {
        cin >> companies[i];
    }
    cin >> M;
    int ind1 = 1, ind2 = 0;
    vector<company> c(M);
    for (int i = 0; i < M ; i++) {
        cin >> c[i].id >> c[i].gen >> c[i].count;
    }
    cin >> ind1 >> ind2;
    
    int count = 0;
    vector<string> sevenGen;
    for (int i = 0; i < c.size(); i++) {
        if (c[i].gen == 7) {
            sevenGen.push_back(companies[c[i].id - 1]);
            count++;
        }
    }
    if (sevenGen.size() > 0) {
        cout << "NINCS";
    }else{
        cout << sevenGen.size() << " ";
        for(auto a : sevenGen){
            cout << a << " ";
        }
    }
    
    return 0;
}
