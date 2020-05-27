#include <iostream>
#include<string>
#include <vector>

using namespace std;


struct temp {
    int mint;
    int maxt;
};

int main()
{
    int n = 0, maxDiv = 0, cnt = 1;
    do{
        cout << "Please write the number of days\n" ;
        cin >> n;
        if (n < 0) {
            cerr << "Please write an integer value\n";
        }
    }while(n < 0);
    
    temp Days[n+1];

    for (int i = 1; i <= n; i++) {
        do {
            cout << "Give min and max for this day\n";
            cin >> Days[i].mint >> Days[i].maxt ;
            if (Days[i].mint > Days[i].maxt) {
                cerr << "First value should be greater\n";
            }
        } while (Days[i].mint > Days[i].maxt);
    }
    
//    Start the  algorithm
    maxDiv = Days[1].maxt - Days[1].mint;
    int OutDays[n+1];
    OutDays[1] = 1;
    
    for (int i = 2; i < n; i++) {
        if ((Days[i].maxt - Days[i].mint) == maxDiv) {
            OutDays[cnt] = i;
            cnt++;
        }else if((Days[i].maxt - Days[i].mint) > maxDiv){
            cnt = 1;
            OutDays[cnt] = 1;
            maxDiv = Days[i].maxt - Days[i].mint;
        }
    }
//    output
    cout << "Counter: " << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
        cout << i << " ";
    }
    cout << endl;
    
}
