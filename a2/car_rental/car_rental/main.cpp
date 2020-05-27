//
//  main.cpp
//  car_rental
//
//  Created by Andrei Cristea on 2020. 05. 07..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Tcar{
    string platten;
    int sday, eday;
};

typedef struct Tcar Tcar;

bool notIn(string& item, vector<string>& items){
    int i = 0;
    while (i <= items.size() && item != items[i]) {
        i++;
    }
    return (i > items.size());
}
int main(int argc, const char * argv[]) {
    int cnt = 0, N = 0;
    bool repeat = true;
    cout << "Please enter number of rentings:\n";
    while (repeat) {
        cin >> N;
        repeat = cin.fail() || cin.peek() != '\n' || N < 0;
        repeat ? cerr << "Incorrect number\n" : cerr << "Next Step\n" ;
        cin.clear();
        cin.ignore(999,'\n');
    }
    vector<Tcar> Rentings(N);
    cout << "Enter car rentings:\n";
    for (int i = 0; i < N; i++) {
            repeat = true;
            while (repeat) {
            cin >> Rentings[i].platten >> Rentings[i].sday >> Rentings[i].eday;
            repeat =  Rentings[i].sday < 0 || Rentings[i].eday > 31 || Rentings[i].sday > Rentings[i].eday;
            if(repeat) {cerr << "Please enter correct input\n";};
            repeat = false;
        }
    }
    vector<string> pNumbers;
    pNumbers.push_back(Rentings[0].platten);
    for (int i = 1; i < N; i++) {
        if (notIn(Rentings[i].platten, pNumbers)) {
            pNumbers.push_back(Rentings[i].platten);
        }
    }
    vector<int> rentedDays;
    int j = 1;
    for (int i = 0; i < Rentings.size(); i++) {
        while (Rentings[i].platten != Rentings[j].platten && j < Rentings.size()) {
            j++;
        }
        if (Rentings[i].platten == Rentings[j].platten) {
            rentedDays.push_back((Rentings[i].eday + Rentings[j].eday) - (Rentings[i].sday + Rentings[j].sday));
            Rentings.erase(Rentings.begin() + j);
        }else{
            rentedDays.push_back( Rentings[i].eday - Rentings[i].sday);
        }
        j=(i+2);
    }
    // First task answer
    cout << "List of all the plate numbers\n";
    for (int i = 0; i < rentedDays.size(); i++) {
        cout << pNumbers[i] <<" " << rentedDays[i] << endl;
    }
    return 0;
}
