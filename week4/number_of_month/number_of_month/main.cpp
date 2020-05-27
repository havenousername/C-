//
//  main.cpp
//  number_of_month
//
//  Created by Andrei Cristea on 2020. 05. 01..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//
#include <iostream>
#include <vector>
#include <map>

struct year {
    std::string day;
    std::string month;
};

typedef struct year Year;

bool isInSet(std::string s,std::vector<std::string> v){
    int i = 0;
    bool isIn = false;
    while (i < v.size() && s != v[i]) {
        i++;
    }
    isIn = (i < v.size());
    return isIn;
};

void number_of_month(){
    std::string month = "";
    std::vector<std::string> months= {"January", "February", "March", "April", "May"};
    
    bool notRepeat = false;
    while (notRepeat == false) {
        std::cout << "Please write month name:\n";
        std::cin >> month;
        notRepeat = isInSet(month, months);
        if (notRepeat == false) {
            std::cout << "Please enter the month only. For example \"January\" not \"Jan\"\n";
        }
    }
    
    int i = 0;
    while(month != months[i] && i < months.size()){
        i++;
    }
    std::cerr << "Number of selected month:\n";
    std::cout << i+1 << std::endl;
}

void month_day(){
    int month = 0, day = 0;
    bool repeat = true;
    
    while (repeat) {
        std::cerr << "Please enter number of month and day of it\n";
        std::cin >> month >> day;
        if (month > 12  || month < 1) {
            repeat = true;
            std::cerr << "Wrong value of month!\n";
            continue;
        }
        if (month == 2 && day > 28) {
            repeat = true;
            std::cerr << "Wrong value of day!\n";
        }else if (month % 2 == 0 && day > 30){
            repeat = true;
            std::cerr << "Wrong value of day!\n";
        }else if(month % 2 != 0 && day > 31){
            repeat = true;
            std::cerr << "Wrong value of day!\n";
        }else{
            repeat = false;
        }
    }
    
    int res = 0;
    for (int i = 1;i < month ; i++) {
        if (i % 2 == 0 ) {
            res += 30;
        }else if (i == 2){
            res += 28;
        }else{
            res += 31;
        }
    }
    std::cout << res + day;
}

std::string reverse(const std::string& rev){
    std::string reversed;
    for (long i = rev.size()-1; i >= 0; i--) {
        reversed += rev[i];
        std::cout << rev[i];
    }
    return reversed;
};


std::string monogram(std::string name){
    std::string mono = "";
    for (int i =0; i < name.size(); i++) {
        if (name[i] > 64 && name[i] < 91) {
            mono += name[i];
        }
    }
    return mono;
};

std::string monogramHU(std::string name){
    std::string mono = "";
    bool firstName = true;
    for (int i =0; i < name.size(); i++) {
        if (name[i] > 64 && name[i] < 91) {
            mono += name[i];
            if (firstName) {
                mono += name[i+1];
                i++;
                firstName = false;
            }
        }
    }
    return mono;
};


bool isPrime(int n, int i = 2, int j = 1){
    if (n <= 2 || i == n)
        return true;
    if (n % i == 0)
        return false;
    
    return isPrime(n, i+1);
};

bool is_prime(int n){
    if (n <= 2) {
        return true;
    }
    int i = 2;
    while (i <= n && n % i) {
        i++;
    }
    if (i < n) {
        return false;
    }else{
        return true;
    }
};

void prime_checking(){
    std::vector<int> n;
    int j = 0;
    std::cout << "Please enter number of numbers\n";
    std::cin >> j;
    for(int i = 0; i < j; i++){
        if(is_prime(i)){
            n.push_back(i);
        }
    }
    for(int i = 0; i < n.size(); i++){
        std::cout << n[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    
//    number_of_month();
//    month_day();
   
    
//    std::string hello = reverse("Hello");
    
//    std::cout << "Monogram: " << monogramHU("Cristea Andrei");
    
    
    
    
    return 0;
}
