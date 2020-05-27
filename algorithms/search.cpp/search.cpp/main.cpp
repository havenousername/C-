//
//  main.cpp
//  search.cpp
//
//  Created by Andrei Cristea on 2020. 04. 23..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N = 0;
    bool repeat = true;

    while(repeat){
        cout << "Please write number of students. It should be positive integer(n > 0)\n";
        cin >> N;
        repeat = cin.fail() || cin.peek() != '\n' || N < 1;
        if (repeat) {
            cout << "Wrong! Your number should be greater than zero and not string!\n";
        }
        cin.clear();
        cin.ignore(999, '\n');
    }
    
    int marks[N];
    for (int i = 1; i <= N; i++) {
        repeat = true;
        while(repeat){
            cout << "Please write mark of the student. It should be in range from 1 to 5. Student: " << i << endl;
            cin >> marks[i];
            repeat = cin.fail() || cin.peek() != '\n' || (marks[i] < 1 || marks[i] > 5);
            if (repeat) {
                cout << "Wrong! Your number should in range (1 to 5) and not string!\n";
            }
            cin.clear();
            cin.ignore(999, '\n');
        }
    }
    
    int  i = 1;
    while(i <= N && marks[i] != 1){
        i++;
    }
    bool Fals = (i <= N);
    int CI = 0;
    if (Fals) {
        CI = i;
    }
    
    
    cout << "Is there any student, who has mark 1?: " << Fals << "\n";
    if (Fals) {
        cout << "Index of the student who failed: " << CI << "\n";
    }
    return 0;
}
