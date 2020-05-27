//
//  main.cpp
//  c2
//
//  Created by Andrei Cristea on 2020. 04. 28..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdint.h>


int cin_validator(int v1, int v2){
    int input = 0;
    bool repeat = true;
    while (repeat) {
//        std::cerr << "Please enter the right value\n";
        std::cin >> input;
//        repeat = std::cin.fail() || std::cin.peek()!='\n' || input < v1 || input > v2;
        repeat = input < v1 || input > v2;
        if(repeat) std::cerr << "You have entered a wrong value.\n Please insert a value bw " << v1 << " and " << v2 << std::endl;
        std::cin.clear();
        std::cin.ignore(999,'\n');
        
    }
    return input;
};

std::vector<int> cin_vector(std::vector<int>& v1, int N){
    for (int i = 1; i <= N; i++) {
        v1.push_back(cin_validator(0, 300));
    }
    return v1;
};

int main(int argc, const char * argv[]) {
    int count = 0;
    int N = cin_validator(0, 100);
    int K = cin_validator(0, 300);
    std::vector<int> v;
    cin_vector(v, N);
    
    std::vector<int> res;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < K) {
            count++;
            res.push_back(i+1);
        }
    }
    std::cout << count << " ";
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    return 0;
}
