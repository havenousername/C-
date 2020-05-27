#include <iostream>
using namespace std;

struct Date {
  int month, day;
};

int main() {
      int n;
    cout << "Please enter number of birthdays:" << endl;
    cin >> n;
    Date birth[n + 1];
    
    for (int i = 1; i <= n; i++) {
        bool repeat = true;
        while (repeat) {
            cout << "Please enter a date (1<=month<=12 1<=day<=31):" << endl;
            cin >> birth[i].month >> birth[i].day;
            repeat = cin.fail() || cin.peek() != '\n' ||  birth[i].month < 1 || birth[i].month > 12 || birth[i].day < 1 || birth[i].day > 31;
            if (repeat) cout << "Wrong date, please enter again!" << endl;
        }
    }
    
    int first = 1;
    for (int i = 2; i <= n; i++) {
        if (birth[i].month < birth[first].month ||
            (birth[i].month == birth[first].month
            && birth[i].day < birth[first].day)) {
            first = i;
        }
    }

    cout << "First birthday in year: " << birth[first].month
         << " " << birth[first].day << ", person " << first << endl;
    return 0;
}

