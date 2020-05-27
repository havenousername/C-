//
//  main.cpp
//  week06
//
//  Created by Andrei Cristea on 2020. 05. 01..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>


struct Animal {
    std::string species;
    int age;
    std::string color;
};

typedef struct Animal animal;

int count_animal(const std::vector<animal>& animals,std::string an){
    int count = 0;
    
    for (int i = 0; i < animals.size(); i++) {
        if (animals[i].species == an) {
            count++;
        }
    }
    
    
    return count;
};

bool is_black(const std::vector<animal>& animals,std::string color){
    bool is_true = false;
    int  i = 0;
    while (i < animals.size() && color != animals[i].color) {
        i++;
    }
    is_true = i < animals.size();
    return is_true;
};

std::vector<int> after_year(const std::vector<animal>& animals){
    std::vector<int> ages;
    for (int i = 0; i < animals.size(); i++) {
        ages.push_back(animals[i].age +1);
    }
    
    return ages;
};

std::vector<animal> give_age(const std::vector<animal>& animals, int age = 2){
    std::vector<animal> a;
    for (int i = 0; i < animals.size(); i++) {
        if (animals[i].age >= age && animals[i].species == "cow") {
            a.push_back(animals[i]);
        }
    }
    
    return a;
};

bool is_unique(const std::vector<animal>& animals, std::string animal){

    bool is_true = true;
    int i = 0;
    while (i < animals.size() && animal != animals[i].species) {
        i++;
    }
    is_true = !(i < animals.size());
    return is_true;
};


int count_diff(std::vector<animal>& animals){
    int cnt = 0;
    for (int i = 0; i < animals.size(); i++) {
        if(!is_unique(animals, animals[i].species)){
            animals.erase(animals.begin() +i);
        }
    }
    for (int i = 0; i < animals.size(); i++) {
        cnt++;
    }
    return cnt;
}

long count_diff_color(std::vector<animal>& animals, std::string species){
    
    std::set<std::string> str;
    for (int i = 0; i < animals.size(); ++i) {
        if (species == animals[i].species) {
            str.insert(animals[i].color);
        }
    }

    return str.size();
};




std::vector<int> count(std::vector<animal>& animals){
    std::vector<int> count;
    std::set<std::string> unique_animals;
    for (int i = 0; i < animals.size(); i++) {
        unique_animals.insert(animals[i].species);
    }
    for(auto a : unique_animals) {
         int temp = count_animal(animals, a);
         count.push_back(temp);
    }
    return count;
};

int main(int argc, const char * argv[]) {
    std::vector<animal> animals= {
        {"pig", 2, "gray"},
        {"pig", 3, "pink"},
        {"pig", 3, "pink"},
        {"lamb", 1, "black"},
        {"cow", 3, "brownish-grey"},
        {"cow", 2, "tan"},
        {"lamb", 2, "grey"},
        {"cow", 4, "reddish-brown"}
    };
    
    
//    std::cout << count_animal(animals, "cow");
//    std::cout << is_black(animals, "black");
//    for (int i = 0; i < 2; i++) {
//         std::cout << give_age(animals, 2)[i].color;
//    }
//    std::cout << count_diff(animals);
//    std::cout << count_diff_color(animals, "pig");
//    for (int i =0; i < count(animals).size(); i++) {
//        std::cout << count(animals)[i] << std::endl;
//    }
    
    return 0;
}
