#include <iostream>
#include <vector>
//#include <string>

using namespace std;


int main() {
    int n, iter = 0;
    cin >> n;

    while(n--){
        int count = 0;

        for (auto j = 0; j < 5; j++) {
            cin >> iter;
            if(iter == 1){
                count++;
            }
        }
        if (count == 0) {
            cout << "\nBeginner\n";
        }else if (count == 1){
            cout << "Junior Developer\n";
        }else if (count == 2){
            cout << "Middle Developer\n";
        }else if(count == 3){
            cout << "Senior Developer\n";
        }else if(count == 4){
            cout << "Hacker\n";
        }else if(count == 5){
            cout << "Jeef Dean\n";
        }
        count = 0;
    }

    string v = "Hello ";
    return 0;
}
