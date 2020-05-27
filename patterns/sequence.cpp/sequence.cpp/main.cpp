//
//  main.cpp
//  sequence.cpp
//
//  Created by Andrei Cristea on 2020. 04. 09..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


int main(int argc, const char * argv[]) {
    int numberInArr = 0;
    int fail = 1, ci = 0;
    do {
        cout << "Write number of elements in the sequence\n";
        cin >> numberInArr;
        if (numberInArr < 0) {
            cerr << "Please input integer numbers\n";
        }
    } while (numberInArr < 0);
    
    vector<int> mark(numberInArr+1);
    for (int i = 1; i < mark.size(); i++) {
        cout << "Write marks of the student separated by line \n";
        cin >> mark[i];
        if (mark[i] > 5 || mark[i] < 1){
            while (mark[i] > 5 || mark[i] < 1){
                cout << "Write in only numbers in range from 1 to 5. Write "<< mark.size()-i <<" more values\n";
                cin >> mark[i];
            }
        };
    }
    
    int i = 1;
    while (i <= numberInArr && mark[i] != 1) {
        i++;
        fail = i;
    }
    cout << "\n";
    if (fail > 0) {
        ci = mark[fail];
        cout << "Number of the subject starting from one: "<< fail << endl;
        cout << "Note: " << ci << endl;
    }
    
    
    
    return 0;
}
