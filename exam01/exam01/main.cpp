//
//  main.cpp
//  exam01
//
//  Created by Andrei Cristea on 2020. 04. 21..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//  W61RAB

#include <iostream>
#include <vector>

// Multiple item selection

struct Temp{
    int maxt;
    int mint;
};

using namespace std;

int main(int argc, const char * argv[]) {
    int N = 0;
    int NCnt = 1;
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
    
    Temp Days[N+1];
    
    for (int i = 1; i <= N; i++) {
        repeat = true;
        
        while (repeat) {
            cout << "Please enter minimum temperature at the day: " << i << "\n";
            cin >> Days[i].mint;
            // Error if its not an integer and is less than 0
            repeat = cin.fail() || cin.peek() != '\n';
            if(repeat) cout << "Wrong! Please try again to write minimal temperature(>0).\n";
            cin.clear();
            cin.ignore(999, '\n');
        }
        
        repeat = true;
        while (repeat) {
            cout << "Please enter maximum temperature at the day: " << i << "\n";
            cin >> Days[i].maxt;
            // Error if its not an integer and is less than 0
            repeat = cin.fail() || cin.peek() != '\n' || Days[i].maxt < Days[i].mint;
            if(repeat) cout << "Wrong! Please try again to write maximum temperature, which is bigger than the mimumal one.\n";
            cin.clear();
            cin.ignore(999, '\n');
        }
        
    }
    vector<int> OutDays(1);
    int MaxDif = Days[1].maxt - Days[1].mint;
    OutDays[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (Days[i].maxt-Days[i].mint == MaxDif) {
            NCnt++;
            OutDays[NCnt] = i;
        }
        if (Days[i].maxt-Days[i].mint > MaxDif) {
            NCnt = 1;
            OutDays[NCnt] = i;
            MaxDif=Days[i].maxt-Days[i].mint;
        }
    }
    
    cout <<"The number of days with biggest difference: "<< NCnt << endl;
    cout << "The indexes of these days: ";
    for (int i = 1; i <= OutDays.size(); i++) {
        cout << "Day: "<< OutDays[i] << endl;
    }
    cout << endl;
    cout << "The maximum difference: " << MaxDif << endl;
    
    return 0;
}
