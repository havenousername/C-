#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    bool repeat = true;
    // Input reading with syntax and semantic error check
    while (repeat) {
        cout << "Please enter the count of elements! (integer number, 1<=number<=20)" << endl;
        cin >> count;
        // Error, if it is not an integer or less than 1 or greater than 20
        repeat = cin.fail() || cin.peek()!='\n' || count < 1 || count > 20;
        if (repeat) cout << "You entered a string or an invalid number." << endl;
        cin.clear();
        cin.ignore(999, '\n');
    }

    int numbers[count + 1];
    // Array input reading
    for (int i = 1; i <= count; i++) {
        repeat = true;
        while (repeat) {
            cout << "Please enter the " << i << " element! (integer number, 0<=number<=100)" << endl;
            cin >> numbers[i];
            // Error, if it is not an integer or  less than 0 or greater than 100
            repeat = cin.fail() || cin.peek() != '\n' || numbers[i] < 0 || numbers[i] > 100;
            if (repeat) cout << "You entered a string or an invalid number." << endl;
            cin.clear();
            cin.ignore(999, '\n');
        }
    }

    string words[count + 1];
    for (int i = 1; i <= count; i++) {
        repeat = true;
        while (repeat) {
            cout << "Please enter the " << i << " word! (string without spaces)" << endl;
            cin >> words[i];
            repeat = cin.fail() || cin.peek() != '\n';
            if (repeat) cout << "Your input has a space." << endl;
            cin.clear();
            cin.ignore(999, '\n');
        }
    }
    return 0;
}
