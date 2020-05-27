//
//  main.cpp
//  exam02
//
//  Created by Andrei Cristea on 2020. 04. 21..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//  W61RAB

#include <iostream>
#include <vector>

// Multiple item selection

struct Days{
    int maxt;
    int mint;
};

using namespace std;

int main(int argc, const char * argv[]) {
    int N = 0;
    int nCount = 1;
    bool repeat = true;
    
    while (repeat) {
        cout << "Please enter the number of days(>0)\n";
        cin >> N;
        // Error if its not an integer or if N < 0
        repeat = cin.fail() || cin.peek() != '\n' || N < 1;
        if(repeat) cout << "Wrong! Please try again.\n";
        cin.clear();
        cin.ignore(999, '\n');
    }
    
    Days days[N];
    
    for (int i = 1; i <= N; i++) {
        bool repeat = true;
        
        while (repeat) {
            cout << "Please enter minimum temperature at the day: " << i << "\n";
            cin >> days[i].mint;
            // Error if its not an integer and is less than 0
            repeat = cin.fail() || cin.peek() != '\n' || days[i].mint < 1;
            if(repeat) cout << "Wrong! Please try again to write minimal temperature(>0).\n";
            cin.clear();
            cin.ignore(999, '\n');
        }
        
        repeat = true;
        while (repeat) {
            cout << "Please enter maximum temperature at the day: " << i << "\n";
            cin >> days[i].maxt;
            // Error if its not an integer and is less than 0
            repeat = cin.fail() || cin.peek() != '\n' || days[i].maxt <= days[i].mint;
            if(repeat) cout << "Wrong! Please try again to write maximum temperature, which is bigger than the mimumal one.\n";
            cin.clear();
            cin.ignore(999, '\n');
        }
        
    }
    vector<int> OutDays(1);
    int MinDif = days[1].maxt - days[1].mint;
    OutDays[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (days[i].maxt-days[i].mint == MinDif) {
            nCount++;
            OutDays[nCount] = i;
        }
        if (days[i].maxt-days[i].mint < MinDif) {
            nCount = 1;
            OutDays[nCount] = i;
            MinDif=days[i].maxt-days[i].mint;
        }
    }
    
    cout <<"Count of all minimal amplitudes: "<< nCount << endl;
    for (int i = 1; i <= OutDays.size(); i++) {
        cout << "Day: "<< OutDays[i] << endl;
    }
    
    return 0;
}

