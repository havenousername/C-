//  examReal
//  neptun code: W61RAB
//  Created by Andrei Cristea on 2020. 04. 23..


#include <iostream>
#include <vector>

using namespace std;

struct Temp {
    int min;
    int max;
};

int main(int argc, const char * argv[]) {
    int dayCount = 0;
    bool repeat = true;
    while (repeat) {
        cout << "Please enter the number of days(>=0) and (<=100)\n";
        cin >> dayCount;
        repeat = cin.fail() || cin.peek() != '\n' || dayCount < 0 || dayCount > 100;
        if(repeat) cout << "Wrong! Please try again.\n";
        cin.clear();
        cin.ignore(999, '\n');
    }
    
    Temp Temps[dayCount];
    for (int i = 1; i <= dayCount; i++) {
        repeat = true;
        
        while (repeat) {
            cout << "Please enter day: "<< i << ". Minimum temperature\n";
            cin >> Temps[i].min;
            repeat = cin.fail() || cin.peek() != '\n' || Temps[i].min < -20;
            if(repeat) cout << "Wrong! Please try again. Input is whether a string or a value less than 20\n";
            cin.clear();
            cin.ignore(999, '\n');
        }
        repeat = true;
        
        while (repeat) {
            cout << "Please enter day: "<< i << ". Maximum temperature\n";
            cin >> Temps[i].max;
            repeat = cin.fail() || cin.peek() != '\n' || Temps[i].max > 50 || Temps[i].max < Temps[i].min;
            if(repeat) cout << "Wrong! Please try again. Input is whether a string or a value bigger than 20\n";
            cin.clear();
            cin.ignore(999, '\n');
        }
    }
    
    int i = 1;
    while(i <= dayCount -1 && Temps[i].min > Temps[i+1].min){
        i++;
    }
    bool MonDec = (i <= (dayCount -1));
    
    int PlusMinusCount = 0;
    int PlusMinus[dayCount];
    for (int i = 1; i <= dayCount; i++) {
        if (Temps[i].min < 0 && Temps[i].max > 0) {
            PlusMinusCount++;
            PlusMinus[PlusMinusCount] = i;
        }
    }
    
    cout << "The weather temperature is monotonically decreasing: "  <<  MonDec << endl;
    
    cout << "The indexes those days on which there will be freezing and thawing: ";
    if (PlusMinusCount > 0) {
        for (int i = 1; i <= PlusMinusCount; i++) {
            cout << PlusMinus[i] << " ";
        }
        cout << endl;
    }else{
        cout << "There are no days on which there will be freezing and thawing";
    }
    
    
    
    
    return 0;
}
