//
//  main.cpp
//  atm
//
//  Created by Andrei Cristea on 2020. 05. 01..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>

struct bank {
    int money;
    float take = 2.0f;
};
typedef struct bank Bank;

bool is_five_multiple(int n){
    bool isMultiple = false;
    if (n % 5 == 0) {
        return true;
    }
    return isMultiple;
};

float take_money(Bank b){
    // if (b.take < 1 && b.money < 0) {
       //     return std::abs(b.money);
       // }
       if (is_five_multiple(b.take) && b.take < b.money) {
           return b.money - b.take - 0.50;
       }else{
           return b.money;
       }
};

int main(int argc, const char * argv[]) {
    Bank bank;
    std::cin >> bank.take >> bank.money;
    if (bank.money > 2000) {
        bank.money = 2000;
    }else if(bank.money < -2000){
        bank.money = 0;
    }
    if (bank.take > 2000){
        bank.take = 2000;
    }else if(bank.take < -2000){
        bank.take = 0;
    }
    
    std::cin.clear();
    
    float left = take_money(bank);
    std::cout << left;
    
    return 0;
}
