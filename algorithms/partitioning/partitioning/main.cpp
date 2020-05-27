//
//  main.cpp
//  partitioning
//
//  Created by Andrei Cristea on 2020. 04. 23..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int N = 0;
    bool repeat = true;
    
    while (repeat) {
        cout << "Please enter number of numbers. It should be bigger than 0\n";
        cin >> N;
        repeat = cin.fail() || cin.peek() != '\n' || N < 1;
        if (repeat) {
            cout << "Wrong! Please enter valid number(1,2,..)\n";
        }
        cin.clear();
        cin.ignore(999, '\n');
    }
    int Numbers[N];
    int cnt = 0;
    vector<int> Even;
    vector<int> Odd;
    for (int i = 1; i <= N; i++) {
        repeat = true;
        while (repeat) {
            cout << "Please enter decimal number. It should be bigger than 0 and less than 10\n";
            cin >> Numbers[i];
            repeat = cin.fail() || cin.peek() != '\n' || Numbers[i] < 1 || Numbers[i] > 10;
            if (repeat) {
                cout << "Wrong! Please enter valid number(1,2,..10)\n";
            }
            cin.clear();
            cin.ignore(999, '\n');
        }
    }
    for (int i = 1; i <= N; i++) {
        if (Numbers[i] % 2 == 0) {
            cnt++;
            Even[cnt] = Numbers[i];
        }else{
            Odd[i-cnt] = Numbers[i];
        }
    }
    
    for (int i = 1; i < ; <#increment#>) {
        <#statements#>
    }
    std::cout << "Hello, World!\n";
    return 0;
}
