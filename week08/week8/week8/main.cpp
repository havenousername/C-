//
//  main.cpp
//  week8
//
//  Created by Andrei Cristea on 2020. 04. 28..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

long long power(long long base, long long exponent) {
    // Write your code here. Make sure to use long long type for the result.
    if(exponent == 1){
      return base;
    }
    else{
      return base * power (base, exponent -1);
    }
};

long long power_loop(long long base, long long exponent){
    long long res = 1;
    while (exponent != 0) {
        res *= base;
        exponent--;
    }
    return res;
};

int gcd(int number1, int number2){
    int result = number1;
    while(result != 1){
        if(number1 % result == 0 && number2 % result == 0){
            return result;
            
        }else{
            result--;
        }
    }
    return result;
};


int gcd_rec(int n1, int n2){
    if (n2 == 0) {
        return n1;
    }else{
        return gcd_rec(n2, n1 % n2);
    }
};

bool is_prime(int num){
    if (num == 1) {
        return false;
    }
    for(int i = 2; i < num; i++){
        if(num % i == 0 || num == 1){
          return false;
        }
    }
    return true;
}

//vector<string>intersection(vector<string>a, vector<string>b)
//{
//  vector<string>c;
//  for (int i=0; i<a.size(); i++)
//  {
//    for (int j=0; j<b.size(); j++)
//    {
//      if(a[i]==b[i])
//      {
//        c.push_back(b[i]);
//      }
//    }
//  }
//  return c;
//}




vector<string> intersection(vector<string> v, vector<string> s){
  vector<string> res;
  for(int i = 0; i < v.size(); i++){
    int j = 0;
    while(j < s.size() && v[i] != s[j]){
      j++;
    }
    if(j < s.size()){
      res.push_back(v[i]);
    }
  }
  return res;
}


int get_cin(){
    int choice = 0;
    
    cout << "Enter choice: \n";
    cin >> setw(1) >> choice;
    
    // Error check
    while (!cin.good()) {
        // Report problem
        cout << "Error: Faulty input. Try again\n";
        // Clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        
        // Get input again
        cout << "Enter choice: \n";
        cin >> setw(1) >> choice;
    }
    // Clear stream
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return choice;
};

int main(int argc, const char * argv[]) {
//    cout << gcd_rec(38, 57) << endl; // 19
//    cout << gcd(10000, gcd(990, 810)) << endl;
//    cout << gcd(2*2*3*3*5, 7*7*13) << endl;
//    cout << gcd(7*23*191, 2*7*29*191) << endl;
//    cout << gcd(283746, 283747) << endl; // 1
//    cout << power_loop(6, 3) << endl;
//    cout << sizeof(int64_t);
//    vector<string> hel = intersection({"hello", "mylove"}, {"hello"});
//    for (int i = 0; i < hel.size(); i++) {
//        cout << hel[i];
//    }

    
    int choice = -1;
    
    choice = get_cin();
    
    while (choice > 0) {
        switch (choice) {
            case 1:
                cout << "Option ONE\n";
                break;
            case 2:
                cout << "Option TWO\n";
                break;
            case 3:
                cout << "Option THREE\n";
                break;
            default:
                cout << "No such CHOISE\n";
                break;
        }
        choice = get_cin();
    }
    
    cout << "Quiting...\n";
//    cout << is_prime(abs(1)) << endl;
//    for (int n = 200; n <= 300; n++) {
//        if (is_prime(n)) {
//            cout << n << " is a prime\n";
//        }
//    }
    return 0;
}
